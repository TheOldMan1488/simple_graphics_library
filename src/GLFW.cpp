#include "GLFW.h"
#include <stdexcept>
#include <GLFW/glfw3.h>


GLFW::GLFW()
{
    if (!glfwInit())
        throw std::runtime_error("GLFW initialization error");
}

GLFW::~GLFW()
{
    glfwTerminate();
}