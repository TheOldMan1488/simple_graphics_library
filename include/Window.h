#pragma once
#include <string>
#include "Color.h"


struct GLFWwindow;

class Window
{
public:
    Window(int width, int heigth, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void clear(Color color);
    void swapBuffers();
    void pollEvents();

private:
    GLFWwindow* window;
};