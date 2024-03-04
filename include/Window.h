#pragma once
#include <string>
#include "Color.h"


struct GLFWwindow;
class Camera;
class Model;

class Window
{
public:
    Window(int width, int height,/* const Camera& camera,*/ const std::string& title);
    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;
    ~Window();

    bool shouldClose() const;
    void clear(Color color);
    void swapBuffers();
    void pollEvents();

    //void setCamera(const Camera& camera);

    void draw(const Model& model);

private:
    GLFWwindow* window;
    //const Camera* camera;
};