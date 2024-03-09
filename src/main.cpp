#include <iostream>
#include <vector>
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
        camera.setTranslation(glm::vec3(0.f, 0.f, 1.5f));
        camera.setFovDegrees(45.f);

        window.setCamera(camera);

        std::vector<Cube> cubes;
        cubes.emplace_back(0.2f, glm::vec3(-1.5f, 1.5f, 0.f));
        cubes.emplace_back(0.2f, glm::vec3(1.5f, 1.5f, 0.f));
        cubes.emplace_back(0.2f, glm::vec3(-1.5f, -1.5f, 0.f));
        cubes.emplace_back(0.2f, glm::vec3(1.5f, -1.5f, 0.f));

        while (!window.shouldClose())
        {
            window.clear(Color(0, 0, 0));

            for (Cube& cube : cubes)
                window.draw(cube);

            for (Cube& cube : cubes)
                cube.rotateDegrees(1.f, glm::vec3(1.f, 0.f, 0.f));
        
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
