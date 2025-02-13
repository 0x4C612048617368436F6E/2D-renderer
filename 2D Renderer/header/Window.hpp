#pragma once
#include"../header/common.hpp"
//class for our window
class Window {
 private:
  size_t windowWidth;
  size_t windowHeight;
  std::string windowTitle;
  GLFWwindow* window = nullptr;

 public:
  //Window();
  Window(size_t width = 800, size_t height = 800,
         std::string Title = "Hello world");
  //framebuffer is the area where output will be displayed
  void setFrameBufferColorBit();
  //others can access the window
  GLFWwindow* getCurrentWindow() { return window;}
  void errorCallback(int code, char* description) { 
	  LOGERROR<std::string>(description);
  }
  ~Window();
};