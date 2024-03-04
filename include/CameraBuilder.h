#pragma once
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/glm.hpp>
#include "Camera.h"


class CameraBuilder
{
public:
    CameraBuilder();
    void setCameraPosition(glm::vec3 position);
    void setCameraTarget(glm::vec3 target);
    void setCameraUpDirection(glm::vec3 upDirection);

    void setFovDegrees(GLfloat fov);
    void setAspectRatio(GLfloat aspectRatio);
    void setNearPlane(GLfloat nearPlane);
    void setFarPlane(GLfloat farPlane);

    Camera getCamera();
    void reset();

private:
    glm::vec3 position, target, upDirection;
    GLfloat fov, aspectRatio, nearPlane, farPlane;
};