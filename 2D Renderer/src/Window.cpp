#include"../header/Window.hpp"

Window::Window(size_t width = 800, size_t height = 800,
               std::string Title = "Hello world") { 
	this->windowWidth = width;
  this->windowHeight = height;
        this->windowTitle = Title;
  WC configureWindowDimension = (WC){this->windowWidth, this->windowHeight};
		//set GLFW hints
		//first check if library supports WINDOW32
        if (glfwPlatformSupported(GLFW_PLATFORM_WIN32)) {
          glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WIN32);
          LOGINFO<std::string>("Platform is supported");
        } else {
          LOGWARNING<std::string>("Library does not support platform");
		}

}

Window::~Window() { 
	glfwDestroyWindow(this->window);
	glfwTerminate(); 
}