#include "CameraBuilder.h"


CameraBuilder::CameraBuilder() :
    position(glm::vec3(0.f, 0.f, 0.f)),
    target(glm::vec3(0.f, 0.f, -1.f)),
    upDirection(glm::vec3(0.f, 1.f, 0.f)),
    fov(45.f),
    aspectRatio(16.f / 9.f),
    nearPlane(0.1f),
    farPlane(100.f)
{

}

void CameraBuilder::setCameraPosition(glm::vec3 position)
{
    this->position = position;
}

void CameraBuilder::setCameraTarget(glm::vec3 target)
{
    this->target = target;
}

void CameraBuilder::setCameraUpDirection(glm::vec3 upDirection)
{
    this->upDirection = upDirection;
}

void CameraBuilder::setFovDegrees(GLfloat fov)
{
    this->fov = fov;
}

void CameraBuilder::setAspectRatio(GLfloat aspectRatio)
{
    this->aspectRatio = aspectRatio;
}

void CameraBuilder::setNearPlane(GLfloat nearPlane)
{
    this->nearPlane = nearPlane;
}

void CameraBuilder::setFarPlane(GLfloat farPlane)
{
    this->farPlane = farPlane;
}

Camera CameraBuilder::getCamera()
{
    glm::mat4 viewMatrix = glm::lookAt(this->position, this->target, this->upDirection);
    glm::mat4 perspectiveMatrix = glm::perspective(this->fov, this->aspectRatio, this->nearPlane, this->farPlane);

    return Camera(viewMatrix, perspectiveMatrix);
}

void CameraBuilder::reset()
{
    this->position = glm::vec3(0.f, 0.f, 0.f);
    this->target = glm::vec3(0.f, 0.f, -1.f);
    this->upDirection = glm::vec3(0.f, 1.f, 0.f);
    this->fov = 45.f;
    this->aspectRatio = 16.f / 9.f;
    this->nearPlane = 0.1f;
    this->farPlane = 100.f;
}
