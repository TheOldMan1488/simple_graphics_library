#include "Window.h"
#include "Camera.h"
#include "Model.h"
#include <stdexcept>
#include <GLFW/glfw3.h>
#include "Color.h"


Window::Window(int width, int height, const std::string& title) : camera(nullptr)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 16);

    glViewport(0, 0, 900, 600);

    this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!this->window)
        throw std::runtime_error("Window creating error");
    
    glfwMakeContextCurrent(this->window);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_MULTISAMPLE);

    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(this->window, Window::framebufferSizeCallback);
    glfwSetWindowUserPointer(this->window, this);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(this->window);
}

void Window::clear(Color color)
{
    auto [red, green, blue, alpha] = color.getGlValue();
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(this->window);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::setCamera(Camera& camera)
{
    this->camera = &camera;
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    Window* windowObject = (Window*)glfwGetWindowUserPointer(window);
    if (!windowObject)
        return;

    if (windowObject->camera)
        windowObject->camera->setAspectRatio((float)width / height);
}

void Window::draw(const Model& model)
{
    model.draw(this->camera->getViewMatrix(), this->camera->getProjectionMatrix());
}