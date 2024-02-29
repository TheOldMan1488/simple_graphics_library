#include "ShaderLoader.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <gl/glew.h>
#include <gl/gl.h>


using namespace glslLoader;

ShaderLoader::ShaderLoader() : shader()
{
}

void ShaderLoader::createShader(GLenum glShaderType)
{
    GLuint shaderId = glCreateShader(glShaderType);

    if (!shaderId)
        throw std::runtime_error("Shader creating Error");

    this->shader.setId(shaderId);
    this->shader.setType(glShaderType);
}

void ShaderLoader::loadSourceFromFile(const std::string& fileName)
{
    std::ifstream shaderFile(fileName);
    if (!shaderFile.is_open())
        throw std::runtime_error("Shader file \"" + fileName + "\" opening error");

    std::string shaderSource = "";
    std::string line = "";
    while (std::getline(shaderFile, line))
        shaderSource += line + '\n';

    shaderFile.close();
    const char* shaderSourceCStr = shaderSource.c_str();

    glShaderSource(this->shader.id, 1, &shaderSourceCStr, nullptr);
}

void ShaderLoader::loadSourceFromString(const std::string& shaderSource)
{
    const char* shaderSourceCStr = shaderSource.c_str();

    glShaderSource(this->shader.id, 1, &shaderSourceCStr, nullptr);
}

void ShaderLoader::compile()
{
    glCompileShader(this->shader.id);

    GLint compileStatus;
    glGetShaderiv(this->shader.id, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_TRUE)
        return;

    GLint infoLogLength;
    glGetShaderiv(this->shader.id, GL_INFO_LOG_LENGTH, &infoLogLength);
    char* infoLogCStr = new char[infoLogLength];
    glGetShaderInfoLog(this->shader.id, infoLogLength, nullptr, infoLogCStr);
    std::string infoLog(infoLogCStr);
    delete[] infoLogCStr;
    glDeleteShader(this->shader.id);
    this->shader.id = 0;

    throw std::runtime_error("Shader compilation error: " + infoLog);
}

Shader ShaderLoader::getShader()
{
    return std::move(this->shader);
}