#pragma once
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{
    friend class CameraBuilder;
public:
    Camera();

    void setPosition(glm::vec3 position);
    void setTarget(glm::vec3 target);
    void setUpDirection(glm::vec3 upDirection);

    void setFovDegrees(GLfloat fov);
    void setAspectRatio(GLfloat aspectRatio);
    void setNearPlane(GLfloat nearPlane);
    void setFarPlane(GLfloat farPlane);

    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

private:
    glm::vec3 position, target, upDirection;
    GLfloat fov, aspectRatio, nearPlane, farPlane;
};