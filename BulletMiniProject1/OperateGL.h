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

        // 창을 띄운다.
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_STENCIL);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(windowwidth, windowheight);
        glutCreateWindow("OpenGL");

       
        // 바둑판의 좌표들을 입력해준다.x, y
        for (int y = 1; y <= 15; y++)
            for (int x = 0; x < 15; x++)
            {
                matrix[y - 1][x][0] = ((float)x / 15);
                matrix[y - 1][x][1] = 1.f - ((float)y / 15);
            }

        //init을 1에서 0으로 변경해준다.(다시 시작안되게함)
        init = 0;

        // 준비되면 화면을 띄운다.
        glFlush();
    }

    void resetGame(float matrix[15][15][3])
    {
        // 바둑판의 바둑좌표에 상태를 초기화 해준다.
        for (int y = 0; y < 15; y++)
            for (int x = 0; x < 15; x++)
            {
                matrix[y][x][2] = 0;
            }

        // 시작인 경우 Restart를 0으로 돌려준다. 재시작을 할 경우restart 1이 되게한다.
        restart = 0;
    }

    

};

