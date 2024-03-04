#include "Camera.h"


glm::mat4 Camera::getProjectionMatrix()
{
    return this->projectionMatrix;
}

glm::mat4 Camera::getViewMatrix()
{
    return this->viewMatrix;
}

void Camera::setProjectionMatrix(glm::mat4 projectionMatrix)
{
    this->projectionMatrix = projectionMatrix;
}

void Camera::setViewMatrix(glm::mat4 viewMatrix)
{
    this->viewMatrix = viewMatrix;
}

Camera::Camera(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) : 
    viewMatrix(viewMatrix),
    projectionMatrix(projectionMatrix)
{

}
