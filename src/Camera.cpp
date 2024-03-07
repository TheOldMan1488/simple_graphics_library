#include "Camera.h"


Camera::Camera() :
    position(glm::vec3(0.f, 0.f, 0.f)),
    target(glm::vec3(0.f, 0.f, -1.f)),
    upDirection(glm::vec3(0.f, 1.f, 0.f)),
    fov(45.f),
    aspectRatio(16.f / 9.f),
    nearPlane(0.1f),
    farPlane(100.f)
{
}

void Camera::setPosition(glm::vec3 position)
{
    this->position = position;
}

void Camera::setTarget(glm::vec3 target)
{
    this->target = target;
}

void Camera::setUpDirection(glm::vec3 upDirection)
{
    this->upDirection = upDirection;
}

void Camera::setFovDegrees(GLfloat fov)
{
    this->fov = fov;
}

void Camera::setAspectRatio(GLfloat aspectRatio)
{
    this->aspectRatio = aspectRatio;
}

void Camera::setNearPlane(GLfloat nearPlane)
{
    this->nearPlane = nearPlane;
}

void Camera::setFarPlane(GLfloat farPlane)
{
    this->farPlane = farPlane;
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(this->fov, this->aspectRatio, this->nearPlane, this->farPlane);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(this->position, this->target, this->upDirection);
}
