#include "Cube.h"
#include <random>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glsl_loader/ShaderLoader.h>


Cube::Cube(GLfloat size, glm::vec3 position)
{
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    glGenBuffers(1, &this->positionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->positionVBO);
    GLfloat vertices[] = {
        -1.f, -1.f, 1.f,//A  0
        1.f, -1.f, 1.f,//B   1
        1.f, -1.f, -1.f,//C  2
        -1.f, -1.f, -1.f,//D 3
        -1.f, 1.f, 1.f,//A1  4
        1.f, 1.f, 1.f,//B1   5
        1.f, 1.f, -1.f,//C1  6
        -1.f, 1.f, -1.f//D1  7
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);

    glGenBuffers(1, &this->colorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->colorVBO);
    GLfloat colors[32];
    this->randomizeColorBuffer(32, 4, colors);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);

    glGenBuffers(1, &this->indexEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexEBO);
    GLuint indices[] = {
        0, 1, 2,//ABC
        0, 2, 3,//ACD
        4, 5, 6,//A1B1C1
        4, 6, 7,//A1C1D1
        3, 7, 4,//DD1A1
        3, 4, 0,//DA1A
        0, 4, 5,//AA1B1
        0, 5, 1,//AB1B
        1, 5, 6,//BB1C1
        1, 6, 2,//BC1C
        2, 6, 7,//CC1D1
        2, 7, 3//CD1D
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glslLoader::ShaderLoader shaderLoader;

    std::string cubeShadersPath = "shaders/cube/";
    std::string shaderFileExtension = ".glsl";

    std::string vertexShaderName = "vertex_shader" + shaderFileExtension;
    std::string fragmentShaderName = "fragment_shader" + shaderFileExtension;

	shaderLoader.createShader(GL_VERTEX_SHADER);
    shaderLoader.loadSourceFromFile(cubeShadersPath + vertexShaderName);
    shaderLoader.compileShader();
    glslLoader::Shader vertexShader = shaderLoader.getShader();

    shaderLoader.createShader(GL_FRAGMENT_SHADER);
    shaderLoader.loadSourceFromFile(cubeShadersPath + fragmentShaderName);
    shaderLoader.compileShader();
    glslLoader::Shader fragmentShader = shaderLoader.getShader();

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, fragmentShader.getId());
    glAttachShader(this->shaderProgram, vertexShader.getId());
    glLinkProgram(this->shaderProgram);

    this->setScaling(glm::vec3(size));
    this->setTranslation(position);
}   

void Cube::draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) const
{
    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glUseProgram(this->shaderProgram);

    GLuint viewMatrixId = glGetUniformLocation(this->shaderProgram, "view");
    glUniformMatrix4fv(viewMatrixId, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    GLuint projectionMatrixId = glGetUniformLocation(this->shaderProgram, "projection");
    glUniformMatrix4fv(projectionMatrixId, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    GLuint modelMatrixId = glGetUniformLocation(this->shaderProgram, "model");
    glm::mat4 modelMatrix = this->getModelMatrix();
    glUniformMatrix4fv(modelMatrixId, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Cube::randomizeColorBuffer(size_t size, GLint step, GLfloat* buffer)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.f, 1.f);

    for (size_t i = 0; i < size; i += step)
    {
        for (int j = 0; j < step; ++j)
        {
            if (j == 3)
            {
                buffer[i + j] = 0.7f;
                continue;
            }

            buffer[i + j] = dist(gen);
        }
    }
}