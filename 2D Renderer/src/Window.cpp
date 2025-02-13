#include"../header/Window.hpp"

Window::Window(size_t width, size_t height,
               std::string Title) { 
	this->windowWidth = width;
  this->windowHeight = height;
        this->windowTitle = Title;
  configureWindowDimension = DEFAULTWINDOWCONFIGURATION;
  //reset the window dimensions
  configureWindowDimension.width = this->windowWidth;
  configureWindowDimension.height = this->windowHeight;
}

void Window::CreateWindow() {
  // set GLFW hints
  // first check if library supports WINDOW32
  if (glfwPlatformSupported(GLFW_PLATFORM_WIN32)) {
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WIN32);
    LOGINFO<std::string>("Platform is supported");
  } else {
    LOGWARNING<std::string>("Library does not support platform");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // initialise glfw
  signed int GLFWINITSIGNAL = glfwInit();
  if (GLFWINITSIGNAL == GL_FALSE) {
    LOGERROR<std::string>("Unable to initialise GLFW");
    glfwDestroyWindow(this->window);
    exit(EXIT_FAILURE);
  }
  // callback to get GLFW error when any
  glfwSetErrorCallback(Window::errorCallback);

  // GLFW initialise successfully
  LOGINFO<std::string>("GLFW Initialised successfully");
  // create window
  this->window = glfwCreateWindow(configureWindowDimension.width,
                                  configureWindowDimension.height,
                                  (this->windowTitle).c_str(), NULL, NULL);
  if (window == NULL) {
    LOGERROR<std::string>("Unable to create Window");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  //set context
  glfwMakeContextCurrent(this->window);
  //load openGL functions
  int OPENGLLOADVALUE = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  if (!OPENGLLOADVALUE) {
    LOGERROR<std::string>("Unable to Load OpenGL function symbols");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  LOGINFO<std::string>("Loaded OpenGL function symbols");
  //configure viewport
  glViewport(configureViewPortDimension.initialX,
             configureViewPortDimension.initialY,
      configureViewPortDimension.finalX, configureViewPortDimension.finalY);
  //configure callback to track winow
  //dimension
  glfwSetFramebufferSizeCallback(this->window,
                                 Window::RenderDisplayResizeCallBack);
  //loop to keep window running
  while (!glfwWindowShouldClose(this->window)) {
    glClearColor(windowColor.RED, windowColor.GREEN, windowColor.BLUE,
                 windowColor.ALPHA);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(this->window);
  }
}

void Window::setWindowColor(float RED, float GREEN,
                                          float BLUE,
                                          float ALPHA) {
  windowColor = FrameBufferColorBitWhite;
  windowColor.RED = RED;
  windowColor.BLUE = BLUE;
  windowColor.GREEN = GREEN;
  windowColor.ALPHA = ALPHA;
}

void Window::setRenderDisplay(int initialX, int initialY, int width,
    int height) {
  configureViewPortDimension.initialX = initialX;
  configureViewPortDimension.initialY = initialY;
  configureViewPortDimension.finalX = width;
  configureViewPortDimension.finalX = height;
}

void Window::RenderDisplayResizeCallBack(GLFWwindow* window,int width, int height) {
  std::string res;
  res.reserve(20);
  res = "Width: " + std::to_string(width) + " Height: " + std::to_string(height);
  
  LOGINFO<std::string>(res);
}

void Window::errorCallback(int code, const char* description) {
  LOGERROR<std::string>(description);
}

Window::~Window() { 
	glfwDestroyWindow(this->window);
	glfwTerminate(); 
}