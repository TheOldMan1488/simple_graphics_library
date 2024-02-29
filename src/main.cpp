#include <iostream>
#include "GLEW.h"
#include "GLFW.h"
#include "Window.h"
#include "Cube.h"


int main()
{
    try
    {
        GLFW glfw;
        Window window(900, 600, "gl");
        GLEW glew;

        Cube cube(0.3f);

        while (!window.shouldClose())
        {
            window.clear(Color(0, 0, 0));

            cube.draw();
        
            window.swapBuffers();
            window.pollEvents();
        }
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    

    return 0;
}
