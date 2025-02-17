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

  float shapeSize = 1.0f;

 public:
  //Window();
  Window(size_t width = 800, size_t height = 800,
         std::string Title = "Hello world");
  //framebuffer is the area where output will be displayed
  void setWindowColor(float RED = 1.0f, float GREEN = 1.0f, float BLUE = 1.0f,
                      float ALPHA = 1.0f);
  void setRenderDisplay(int initialX=0, int initialY=0,int width=800, int height=800);
  void CreateWindow();
  //others can access the window
  GLFWwindow* getCurrentWindow() { return window;}
  static void errorCallback(int code, const char* description);
  void drawTriangle(float size=0);
  void triangleSize(float size = 1.0f);
  void loadTexture(std::string path);
  ~Window();
};