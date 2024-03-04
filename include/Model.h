#pragma once
#include <string>
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/glm.hpp>


class Model
{
public:    
    Model();
    virtual ~Model();

    virtual void draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) = 0;

protected:
    GLuint VAO;
    GLuint positionVBO;
    GLuint colorVBO;
    GLuint indexEBO;

    GLuint shaderProgram;
};