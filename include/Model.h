#pragma once
#include <string>
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>


class Model
{
public:    
    Model();
    virtual ~Model();

    virtual void draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) const = 0;

    void scale(glm::vec3 scaling);
    void translate(glm::vec3 translation);
    void rotateDegrees(GLfloat angle, glm::vec3 axis);
    
    void setScaling(glm::vec3 scaling);
    void setTranslation(glm::vec3 translation);
    void setRotationDegrees(GLfloat angle, glm::vec3 axis);

protected:
    GLuint VAO;
    GLuint positionVBO;
    GLuint colorVBO;
    GLuint indexEBO;

    GLuint shaderProgram;

    glm::vec3 scaling;
    glm::vec3 translation;
    glm::quat rotation;

    glm::mat4 getModelMatrix() const;
};