#pragma once
#include"../header/common.hpp"
class renderObject {
 private:
	 //create stuff needed for each shapes
	 //triangle
  float triangleVertexAttributes[9] = {
	  0.0f, 1.0f, 0.0f,
	  -1.0f, -1.0f, 0.0f,
	  1.0f, -1.0f, 0.0f
  };
 public:
  renderObject();
  //we will start with basic shapes then move to
  //more complicated

  //Triangle
  void drawTraingle(size_t X1, size_t Y1, size_t X2, size_t Y2);
  //Rectangle

  //Square
  ~renderObject();
};