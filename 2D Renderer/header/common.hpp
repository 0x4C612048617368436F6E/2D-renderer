#pragma once
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
#include<iostream>
#include"logger.hpp"
#include<string>

typedef struct WindowConfigiration {
 public:
  size_t width;
  size_t height;
}WC;//WC = WindowConfiguration

typedef struct ViewPortConfiguration {
 public:
  size_t initialX;
  size_t initialY;
  size_t finalX;
  size_t finalY;
}VPC;

typedef struct defaultFrameBufferColorBit {
 public:
  float RED = 0.0f;
  float GREEN = 0.0f;
  float BLUE = 0.0f;
  float ALPHA = 0.0f;
} FrameBufferBit;

#define DEFAULTWINDOWCONFIGURATION WC{800, 800}
#define DEFAULTVIEWPORTCONFIGURATION VPC {0,0,800,800}
#define FrameBufferColorBitWhite FrameBufferBit{1.0f, 1.0f, 1.0f, 1.0f}
 
enum class INPUT : int {
  EXIT_BUTTON,
  W_BUTTON,
  A_BUTTON,
  S_BUTTON,
  D_BUTTON,
  ARROW_UP_BUTTON,
  ARROW_DOWN_BUTTON,
  ARROW_LEFT_BUTTON,
  ARROW_RIGHT_BUTTON
};