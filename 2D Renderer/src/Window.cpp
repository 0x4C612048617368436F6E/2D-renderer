#include"../header/Window.hpp"

Window::Window(size_t width, size_t height,
               std::string Title) { 
	this->windowWidth = width;
  this->windowHeight = height;
        this->windowTitle = Title;
  WC configureWindowDimension = DEFAULTWINDOWCONFIGURATION;
		//set GLFW hints
		//first check if library supports WINDOW32
        if (glfwPlatformSupported(GLFW_PLATFORM_WIN32)) {
          glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WIN32);
          LOGINFO<std::string>("Platform is supported");
        } else {
          LOGWARNING<std::string>("Library does not support platform");
		}

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        //initialise glfw
        signed int GLFWINITSIGNAL = glfwInit();
        if (GLFWINITSIGNAL == GL_FALSE)
        {
          LOGERROR<std::string>("Unable to initialise GLFW");
          glfwDestroyWindow(this->window);
          exit(EXIT_FAILURE);
        }
        //GLFW initialise successfully
        LOGINFO<std::string>("GLFW Initialised successfully");
        //create window
        this->window = glfwCreateWindow(this->windowWidth, this->windowHeight,
                             (this->windowTitle).c_str(), NULL, NULL);
        if (window == NULL) {
          LOGERROR<std::string>("Unable to create Window");
          glfwTerminate();
          exit(EXIT_FAILURE);
        }
}

Window::~Window() { 
	glfwDestroyWindow(this->window);
	glfwTerminate(); 
}