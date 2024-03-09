#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>


class Scalable
{
public:
    virtual ~Scalable() = default;
    virtual void scale(glm::vec3 scale) = 0;
    virtual void setScaling(glm::vec3 scale) = 0;
};

class Translatable
{
public:
    virtual ~Translatable() = default;
    virtual void translate(glm::vec3 translation) = 0;
    virtual void setTranslation(glm::vec3 translation) = 0;
};

class Rotatable
{
public:
    virtual ~Rotatable() = default;
    virtual void rotateDegrees(GLfloat angle, glm::vec3 axis) = 0;
    virtual void setRotationDegrees(GLfloat angle, glm::vec3 axis) = 0;
};

class Transformable : public Scalable, public Translatable, public Rotatable
{
};