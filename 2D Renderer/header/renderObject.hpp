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
  UIx64 TriangleVAO;
  UIx64 TriangleVBO;
 public:
  renderObject();
  //we will start with basic shapes then move to
  //more complicated

  //Triangle
  void drawTraingle(size_t X1, size_t Y1, size_t X2, size_t Y2);
  void activateTriagleVAO() const;
  //Rectangle

  //Square
  ~renderObject();
};