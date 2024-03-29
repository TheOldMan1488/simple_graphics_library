#pragma once
#include <string>
#include "Shader.h"


namespace glslLoader
{
    class ShaderLoader
    {
    public:
        ShaderLoader();

        void createShader(GLenum glShaderType);
        void loadSourceFromFile(const std::string& fileName);
        void loadSourceFromString(const std::string& shaderSource);
        void compileShader();
        Shader getShader();

        void resetShader();

    private:
        Shader shader;
    };
}