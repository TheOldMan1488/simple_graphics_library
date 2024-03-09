#pragma once
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Transformable.h"


class Model : public Transformable
{
public:    
    Model();
    Model(Model&& other);
    Model& operator=(Model&& other);
    virtual ~Model();

    virtual void draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) const = 0;

    virtual void scale(glm::vec3 scaling) override;
    virtual void translate(glm::vec3 translation) override;
    virtual void rotateDegrees(GLfloat angle, glm::vec3 axis) override;
    
    virtual void setScaling(glm::vec3 scaling) override;
    virtual void setTranslation(glm::vec3 translation) override;
    virtual void setRotationDegrees(GLfloat angle, glm::vec3 axis) override;

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