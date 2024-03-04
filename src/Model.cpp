#include "Model.h"


Model::Model() : VAO(0), positionVBO(0), colorVBO(0), indexEBO(0), shaderProgram(0)
{

}

Model::~Model()
{
    glDeleteProgram(this->shaderProgram);
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->positionVBO);
    glDeleteBuffers(1, &this->colorVBO);
}