#pragma once
#include "Model.h"


class Cube : public Model
{
public:
    Cube(GLfloat size = 1.f, glm::vec3 position = {0.f, 0.f, 0.f});
    
    virtual void draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) const override;

private:
    void randomizeColorBuffer(size_t size, GLint step, GLfloat* buffer);
};