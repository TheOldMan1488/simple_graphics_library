#include <iostream>
#include "GLEW.h"
#include "GLFW.h"
#include "Window.h"
#include "Cube.h"
#include "CameraBuilder.h"
#include <thread>


int main()
{
    try
    {
        int windowWidth = 900;
        int windowHeight = 600;

        GLFW glfw;
        Window window(windowWidth, windowHeight, "gl");
        GLEW glew;

        CameraBuilder cameraBuilder;
        cameraBuilder.setAspectRatio(float(windowWidth) / windowHeight);
        cameraBuilder.setCameraPosition(glm::vec3(0.f, 0.f, 1.5f));
        cameraBuilder.setFovDegrees(45.f);
        Camera camera = cameraBuilder.getCamera();

        Cube cube(0.3f);

        while (!window.shouldClose())
        {
            window.clear(Color(0, 0, 0));

            cube.draw(camera.getViewMatrix(), camera.getProjectionMatrix());
        
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
