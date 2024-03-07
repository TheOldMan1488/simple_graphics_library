#include "Model.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>


Model::Model() : 
    VAO(0),
    positionVBO(0),
    colorVBO(0),
    indexEBO(0),
    shaderProgram(0),
    scaling(1.f, 1.f, 1.f),
    translation(0.f, 0.f, 0.f),
    rotation(1.f, 0.f, 0.f, 0.f)
{

}

Model::~Model()
{
    glDeleteProgram(this->shaderProgram);
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->positionVBO);
    glDeleteBuffers(1, &this->colorVBO);
}

void Model::scale(glm::vec3 scaling)
{
    this->scaling *= scaling;
}

void Model::translate(glm::vec3 translation)
{
    this->translation += translation;
}

void Model::rotateDegrees(GLfloat angle, glm::vec3 axis)
{
    this->rotation = glm::angleAxis(glm::radians(angle), axis) * this->rotation;
    this->rotation = glm::normalize(this->rotation);
}

void Model::setScaling(glm::vec3 scaling)
{
    this->scaling = scaling;
}

void Model::setTranslation(glm::vec3 translation)
{
    this->translation = translation;
}

void Model::setRotationDegrees(GLfloat angle, glm::vec3 axis)
{
    this->rotation = glm::angleAxis(glm::radians(angle), axis);
}

glm::mat4 Model::getModelMatrix() const
{
    glm::mat4 modelMatrix = glm::mat4(1.f);
    modelMatrix = glm::scale(modelMatrix, this->scaling);
    modelMatrix = glm::translate(modelMatrix, this->translation);
    modelMatrix = modelMatrix * glm::mat4_cast(this->rotation);

    return modelMatrix;
}