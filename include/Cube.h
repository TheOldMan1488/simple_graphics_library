#pragma once
#include "gl/glew.h"
#include "gl/gl.h"


class Cube
{
public:
    Cube(float size);
    ~Cube();
    void draw();

private:
    GLuint VAO;
    GLuint positionVBO;
    GLuint colorVBO;
    GLuint indexEBO;

    GLuint shaderProgram;

    GLfloat angle;

    void randomizeColorBuffer(size_t size, GLint step, GLfloat* buffer);
};