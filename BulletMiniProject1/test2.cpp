#include <GL/glut.h>
#include <GL/GLU.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "DrawView.h"
#include "DrawGL.h"
#include "OperateGL.h"

using namespace std;

float windowwidth = 800;
float windowheight = 800;
float x_width = windowwidth / 2;
float y_height = windowheight / 2;

bool init = 1, restart = 1;
static float mat[15][15][3];
static char Turn = 0;
static int widthWeight = 1.2;

float origin_point_x = 0.065f;
float origin_potin_y = 0.065f;

float Distance = 0, minDistance = 3.f,
minDistanceX = 0, minDistanceY = 0;
int position_x, position_y;

float scale_x = 2.0;
float scale_y = 2.0;
float transf_x = -0.47;
float transf_y = -0.47;

DrawGL gl;
OperateGL os;
//// �ʱ�ȭ�� ����
//void initialization(int argc, char** argv)
//{
//
//    // â�� ����.
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_STENCIL);
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(windowwidth, windowheight);
//    glutCreateWindow("OpenGL");
//
//    // �ٵ����� �׸���.
//    gl.glDrawScale();
//    gl.drawLine();
//
//    // �ٵ����� ��ǥ���� �Է����ش�.x, y
//    for (int y = 1; y <= 15; y++)
//        for (int x = 0; x < 15; x++)
//        {
//            mat[y - 1][x][0] = ((float)x / 15);
//            mat[y - 1][x][1] = 1.f - ((float)y / 15);
//        }
//
//    //init�� 1���� 0���� �������ش�.(�ٽ� ���۾ȵǰ���)
//    init = 0;
//
//    // �غ�Ǹ� ȭ���� ����.
//    glFlush();
//}
//void game_initialization()
//{
//
//    gl.glDrawScale();
//    gl.drawLine();
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    // �ٵ����� �ٵ���ǥ�� ���¸� �ʱ�ȭ ���ش�.
//    for (int y = 0; y < 15; y++)
//        for (int x = 0; x < 15; x++)
//        {
//            mat[y][x][2] = 0;
//        }
//
//    // ������ ��� Restart�� 0���� �����ش�. ������� �� ���restart 1�� �ǰ��Ѵ�.
//    restart = 0;
//}

void mouse_move(int pointX, int pointY)
{
    //std::cout << pointX << " " << pointY << "\n" << std::endl;
    float XX = (float)(pointX - 20) / 800;
    float YY = 0.97f - (float)(pointY) / 800;

    for (int y = 0; y < 15; y++)
        for (int x = 0; x < 15; x++)
        {
            Distance = pow(mat[y][x][0] - XX, 2) + pow(mat[y][x][1] - YY, 2);
            if (minDistance > Distance)
            {
                minDistance = Distance;
                minDistanceX = mat[y][x][0];
                minDistanceY = mat[y][x][1];
                position_x = x;
                position_y = y;
            }
        }

    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.9f, 0.0f, 0.0f);

    glScalef(scale_x, scale_y, 0);

    glTranslatef(transf_x, transf_y, 0);

    glTranslatef(minDistanceX, minDistanceY, 0);

    glutSolidCube(0.02f);

    glPopMatrix();

    minDistance = 3.0f;

    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);

    gl.glDrawScale();

    gl.drawLine();
    gl.glDrawStone(mat);
    
}

void click(int A, int B, int px, int py)
{
    if (B == GLUT_DOWN)
        if (mat[position_y][position_x][2] == 0)
        {
            if (Turn == 0) {
                mat[position_y][position_x][2] = 1;
                Turn = 1;
            }
            else {
                mat[position_y][position_x][2] = 2;
                Turn = 0;
            }
           
        }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q') exit(0);
    else if (key == 'S' || key == 's') os.resetGame(mat);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    // �⺻ ���콺 �̵��� ����� �Լ�.
    glutPassiveMotionFunc(mouse_move);

    // �⺻ ���콺 Ŭ���� ����� �Լ�.
    glutMouseFunc(click);

    // Ű���� �Է½� ����� �Լ�.
    glutKeyboardFunc(keyboard);

    // ȭ���� �׸���.
    gl.glDrawScale();

    gl.drawLine();

    //view.DrawStoneOnBoard(mat);
    gl.glDrawStone(mat);

    // ȭ�鿡 ����.
    glFlush();
}

int main(int argc, char** argv)
{
    // �ʱ�ȭ�� ���� 
    if (init){
        puts("ȭ�� �ʱ�ȭ ����");
        os.initGame(argc, argv, mat);
    }

    if (restart){
        puts("���� �ʱ�ȭ ����");
        os.resetGame(mat);
    }

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}