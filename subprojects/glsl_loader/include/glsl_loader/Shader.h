#pragma once
#include "gl/glew.h"
#include "gl/gl.h"


namespace glslLoader
{
    class Shader
    {
        friend class ShaderLoader;

    public:
        Shader(const Shader&) = delete;
        Shader(Shader&& other);
        Shader& operator=(const Shader&) = delete;
        Shader& operator=(Shader&& other);
        ~Shader();

        GLuint getId() const;
        GLenum getType() const;

    private:
        Shader();

        void setId(GLuint glShaderId);
        void setType(GLenum glShaderType);

        GLuint id;
        GLenum type;
    };
}