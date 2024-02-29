#pragma once
#include <string>
#include <gl/glew.h>
#include <gl/gl.h>


class Model
{
public:    
    Model();
    void draw();

protected:
    

private:
    GLuint VAO;
    GLuint positionVBO;
    GLuint colorVBO;
    GLuint indexEBO;

    GLuint shaderProgram;
};