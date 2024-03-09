#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Transformable.h"


class Camera : public Translatable, public Rotatable
{
    friend class CameraBuilder;
public:
    Camera();

    void setViewDirection(glm::vec3 viewDirection);
    void setUpDirection(glm::vec3 upDirection);

    void setFovDegrees(GLfloat fov);
    void setAspectRatio(GLfloat aspectRatio);
    void setNearPlane(GLfloat nearPlane);
    void setFarPlane(GLfloat farPlane);

    virtual void translate(glm::vec3 translation) override;
    virtual void setTranslation(glm::vec3 translation) override;

    virtual void rotateDegrees(GLfloat angle, glm::vec3 axis) override;
    virtual void setRotationDegrees(GLfloat angle, glm::vec3 axis) override;

    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

private:
    glm::vec3 translation, viewDirection, upDirection;
    GLfloat fov, aspectRatio, nearPlane, farPlane;
};