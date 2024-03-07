#include <iostream>
#include <thread>
#include "GLEW.h"
#include "GLFW.h"
#include "Window.h"
#include "Cube.h"
#include "Camera.h"


int main()
{
    try
    {
        int windowWidth = 900;
        int windowHeight = 600;

        GLFW glfw;
        Window window(windowWidth, windowHeight, "gl");
        GLEW glew;

        Camera camera;
        camera.setAspectRatio(float(windowWidth) / windowHeight);
        camera.setPosition(glm::vec3(0.f, 0.5f, 1.5f));
        camera.setFovDegrees(45.f);
        camera.setFarPlane(10.f);

        window.setCamera(camera);

        Cube cube(0.3f);

        while (!window.shouldClose())
        {
            window.clear(Color(0, 0, 0));

            window.draw(cube);
            cube.rotateDegrees(0.4f, glm::vec3(1.f, 0.f, 1.f));
            cube.translate(glm::vec3(0.f, 0.f, -0.01f));
        
            window.swapBuffers();
            window.pollEvents();

            std::this_thread::sleep_for(std::chrono::milliseconds(8));
        }
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    

    return 0;
}
