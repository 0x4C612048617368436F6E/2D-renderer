#pragma once
#include"../header/common.hpp"
class createShader {
 private:
  std::string stringShaderSource;
  UIx64 createShaderObject();
 public:
  createShader(int shaderTtype,std::vector<std::string> shaderVector);

 public:
  UIx64 createShaderObject();
  std::string getStringShaderSource();
  ~createShader();
};