#pragma once
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
#include<iostream>
#include"logger.hpp"
#include<string>
#include<fstream>
#include<vector>

typedef unsigned int UIx64;

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
  float ALPHA = 1.0f;
} FrameBufferBit;

#define DEFAULTWINDOWCONFIGURATION WC{800, 800}
#define DEFAULTVIEWPORTCONFIGURATION VPC {0,0,800,800}
#define FrameBufferColorBitWhite FrameBufferBit{1.0f, 1.0f, 1.0f, 1.0f}
 
enum class INPUT : unsigned int {
  EXIT_BUTTON = GLFW_KEY_ESCAPE,
  W_BUTTON = GLFW_KEY_W,
  A_BUTTON = GLFW_KEY_A,
  S_BUTTON = GLFW_KEY_S,
  D_BUTTON = GLFW_KEY_D,
  ARROW_UP_BUTTON = GLFW_KEY_UP,
  ARROW_DOWN_BUTTON = GLFW_KEY_DOWN,
  ARROW_LEFT_BUTTON = GLFW_KEY_LEFT,
  ARROW_RIGHT_BUTTON = GLFW_KEY_RIGHT,
  KEY_IS_PRESSED = GLFW_PRESS,
  KEY_IS_RELEASED = GLFW_RELEASE
};
enum class SHADERTYPE : int { 
	VERTEX = 0x8B31,
	FRAGMENT = 0x8B30
};