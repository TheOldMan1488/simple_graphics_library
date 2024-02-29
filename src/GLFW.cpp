#include "GLFW.h"
#include <stdexcept>
#include <glfw/glfw3.h>


GLFW::GLFW()
{
    if (!glfwInit())
        throw std::runtime_error("GLFW initialization error");
}

GLFW::~GLFW()
{
    glfwTerminate();
}