#pragma once
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{
    friend class CameraBuilder;
public:
    Camera() = delete;
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    void setViewMatrix(glm::mat4 viewMatrix);
    void setProjectionMatrix(glm::mat4 projectionMatrix);

private:
    Camera(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};