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
//// 초기화면 설정
//void initialization(int argc, char** argv)
//{
//
//    // 창을 띄운다.
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_STENCIL);
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(windowwidth, windowheight);
//    glutCreateWindow("OpenGL");
//
//    // 바둑판을 그린다.
//    gl.glDrawScale();
//    gl.drawLine();
//
//    // 바둑판의 좌표들을 입력해준다.x, y
//    for (int y = 1; y <= 15; y++)
//        for (int x = 0; x < 15; x++)
//        {
//            mat[y - 1][x][0] = ((float)x / 15);
//            mat[y - 1][x][1] = 1.f - ((float)y / 15);
//        }
//
//    //init을 1에서 0으로 변경해준다.(다시 시작안되게함)
//    init = 0;
//
//    // 준비되면 화면을 띄운다.
//    glFlush();
//}
//void game_initialization()
//{
//
//    gl.glDrawScale();
//    gl.drawLine();
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    // 바둑판의 바둑좌표에 상태를 초기화 해준다.
//    for (int y = 0; y < 15; y++)
//        for (int x = 0; x < 15; x++)
//        {
//            mat[y][x][2] = 0;
//        }
//
//    // 시작인 경우 Restart를 0으로 돌려준다. 재시작을 할 경우restart 1이 되게한다.
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

    // 기본 마우스 이동시 적용될 함수.
    glutPassiveMotionFunc(mouse_move);

    // 기본 마우스 클릭시 적용될 함수.
    glutMouseFunc(click);

    // 키보드 입력시 적용될 함수.
    glutKeyboardFunc(keyboard);

    // 화면을 그린다.
    gl.glDrawScale();

    gl.drawLine();

    //view.DrawStoneOnBoard(mat);
    gl.glDrawStone(mat);

    // 화면에 띄운다.
    glFlush();
}

int main(int argc, char** argv)
{
    // 초기화면 시작 
    if (init){
        puts("화면 초기화 시작");
        os.initGame(argc, argv, mat);
    }

    if (restart){
        puts("게임 초기화 시작");
        os.resetGame(mat);
    }

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}