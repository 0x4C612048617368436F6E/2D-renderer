#pragma once
#include"./common.hpp"
#include"./handleInput.hpp"
#include"./renderObject.hpp"
#include"./createShaderProgram.hpp"
//class for our window
class Window {
 private:
  size_t windowWidth;
  size_t windowHeight;
  std::string windowTitle;
  GLFWwindow* window = nullptr;
  FrameBufferBit windowColor;
  WC configureWindowDimension; //WC = Window dimension
  VPC configureViewPortDimension; //VPC = ViewPort Dimension

 public:
  //Window();
  Window(size_t width = 800, size_t height = 800,
         std::string Title = "Hello world");
  //framebuffer is the area where output will be displayed
  void setWindowColor(float RED = 1.0f, float GREEN = 0.0f, float BLUE = 0.0f,
                      float ALPHA = 1.0f);
  void setRenderDisplay(int initialX, int initialY,int width, int height);
  static void RenderDisplayResizeCallBack(GLFWwindow* window, int width,
                                          int height);
  void CreateWindow();
  //others can access the window
  GLFWwindow* getCurrentWindow() { return window;}
  static void errorCallback(int code, const char* description);
  void drawTriangle();
  ~Window();
};