#include "GLEW.h"
#include <stdexcept>
#include <GL/glew.h>
#include <GL/gl.h>


GLEW::GLEW()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("GLEW initialization error");
}