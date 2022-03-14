#pragma once
#include <GL/glut.h>
#include <GL/GLU.h>
#include <cmath>
#include <iostream>


class OperateGL
{
private:
    float windowwidth = 800;
    float windowheight = 800;
    bool init = 1, restart = 1;

public: 

    void initGame(int argc, char** argv, float matrix[15][15][3])
    {

        // â�� ����.
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_STENCIL);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(windowwidth, windowheight);
        glutCreateWindow("OpenGL");

       
        // �ٵ����� ��ǥ���� �Է����ش�.x, y
        for (int y = 1; y <= 15; y++)
            for (int x = 0; x < 15; x++)
            {
                matrix[y - 1][x][0] = ((float)x / 15);
                matrix[y - 1][x][1] = 1.f - ((float)y / 15);
            }

        //init�� 1���� 0���� �������ش�.(�ٽ� ���۾ȵǰ���)
        init = 0;

        // �غ�Ǹ� ȭ���� ����.
        glFlush();
    }

    void resetGame(float matrix[15][15][3])
    {
        // �ٵ����� �ٵ���ǥ�� ���¸� �ʱ�ȭ ���ش�.
        for (int y = 0; y < 15; y++)
            for (int x = 0; x < 15; x++)
            {
                matrix[y][x][2] = 0;
            }

        // ������ ��� Restart�� 0���� �����ش�. ������� �� ���restart 1�� �ǰ��Ѵ�.
        restart = 0;
    }

    

};

