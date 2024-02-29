#include "Shader.h"


using namespace glslLoader;

Shader::Shader() : id(0), type(0)
{
}

Shader::Shader(Shader&& other) : id(other.id)
{
    other.id = 0;
}

Shader& Shader::operator=(Shader&& other)
{
    if (this == &other)
        return *this;

    this->id = other.id;
    other.id = 0;

    return* this;
}

Shader::~Shader()
{
    glDeleteShader(this->id);
}

GLuint Shader::getId() const
{
    return this->id;
}

GLenum Shader::getType() const
{
    return this->type;
}

void Shader::setId(GLuint glShaderId)
{
    this->id = glShaderId;
}

void Shader::setType(GLenum glShaderType)
{
    this->type = glShaderType;
}
