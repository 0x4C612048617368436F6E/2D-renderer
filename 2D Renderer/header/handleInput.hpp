#pragma once
#include"../header/common.hpp"
class handleInput {
 public:
  handleInput();
  static void MiddlewareHandleInput(GLFWwindow* window, int key, int scancode,
                                    int action, int mods);
  ~handleInput();
};