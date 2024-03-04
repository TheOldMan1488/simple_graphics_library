#pragma once
#include "Model.h"


class Cube : public Model
{
public:
    Cube(float size);
    
    virtual void draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;

private:
    GLfloat angle;

    void randomizeColorBuffer(size_t size, GLint step, GLfloat* buffer);
};