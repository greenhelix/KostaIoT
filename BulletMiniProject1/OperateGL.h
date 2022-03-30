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

    void initGame(int argc, char** argv, float matrix[15][15][3]);

    void resetGame(float matrix[15][15][3]);

};

