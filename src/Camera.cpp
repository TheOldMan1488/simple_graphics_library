#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>


Camera::Camera() :
    translation(glm::vec3(0.f, 0.f, 0.f)),
    viewDirection(glm::vec3(0.f, 0.f, -1.f)),
    upDirection(glm::vec3(0.f, 1.f, 0.f)),
    fov(45.f),
    aspectRatio(16.f / 9.f),
    nearPlane(0.1f),
    farPlane(100.f)
{
}

void Camera::setViewDirection(glm::vec3 viewDirection)
{
    this->viewDirection = glm::normalize(viewDirection);
}

void Camera::setUpDirection(glm::vec3 upDirection)
{
    this->upDirection = glm::normalize(upDirection);
}

void Camera::setFovDegrees(GLfloat fov)
{
    while (fov >= 360)
        fov -= 360;

    while (fov <= -360)
        fov += 360;

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

void Camera::translate(glm::vec3 translation)
{
    this->translation += translation;
}

void Camera::setTranslation(glm::vec3 translation)
{
    this->translation = translation;
}

void Camera::rotateDegrees(GLfloat angle, glm::vec3 axis)
{
    while (angle >= 360)
        angle -= 360;

    while (angle <= -360)
        angle += 360;

    axis = glm::normalize(axis);

    glm::quat rotation = glm::angleAxis(glm::radians(angle), axis);

    this->viewDirection = glm::rotate(rotation, this->viewDirection);
    this->upDirection = glm::rotate(rotation, this->upDirection);
}

void Camera::setRotationDegrees(GLfloat angle, glm::vec3 axis)
{
    while (angle >= 360)
        angle -= 360;

    while (angle <= -360)
        angle += 360;

    axis = glm::normalize(axis);

    glm::quat rotation = glm::angleAxis(glm::radians(angle), axis);

    this->viewDirection = glm::rotate(rotation, glm::vec3(0.f, 0.f, -1.f));
    this->upDirection = glm::rotate(rotation, glm::vec3(0.f, 1.f, 0.f));
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(this->fov, this->aspectRatio, this->nearPlane, this->farPlane);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(this->translation, this->viewDirection + this->translation, this->upDirection);
}
