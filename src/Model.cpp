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

Model::Model(Model&& other) :
    VAO(other.VAO),
    positionVBO(other.positionVBO),
    colorVBO(other.colorVBO),
    indexEBO(other.indexEBO),
    shaderProgram(other.shaderProgram),
    scaling(other.scaling),
    translation(other.translation),
    rotation(other.rotation)
{
    other.VAO = 0;
    other.positionVBO = 0;
    other.colorVBO = 0;
    other.indexEBO = 0;
    other.shaderProgram = 0;
}

Model& Model::operator=(Model&& other)
{
    if (this == &other)
        return *this;

    this->VAO = other.VAO;
    this->positionVBO = other.positionVBO;
    this->colorVBO = other.colorVBO;
    this->indexEBO = other.indexEBO;
    this->shaderProgram = other.shaderProgram;
    this->scaling = other.scaling;
    this->translation = other.translation;
    this->rotation = other.rotation;

    other.VAO = 0;
    other.positionVBO = 0;
    other.colorVBO = 0;
    other.indexEBO = 0;
    other.shaderProgram = 0;

    return *this;
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