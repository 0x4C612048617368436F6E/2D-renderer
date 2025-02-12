#pragma once
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
#include<iostream>
#include"logger.hpp"

typedef struct WindowConfigiration {
 public:
  size_t width;
  size_t height;
}WC;//WC = WindowConfiguration

typedef struct defaultFrameBufferColorBit {
 public:
  float RED = 0.0f;
  float GREEN = 0.0f;
  float BLUE = 0.0f;
  float ALPHA = 0.0f;
} FrameBufferBit;

#define FrameBufferColorBitWhite(FrameBufferBit) {1.0f, 1.0f, 1.0f, 1.0f};
 