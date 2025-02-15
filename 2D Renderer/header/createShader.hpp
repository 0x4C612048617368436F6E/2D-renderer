#pragma once
#include"../header/common.hpp"
class createShader {
 private:
  std::string stringShaderSource;
  // create shader objects
  UIx64 shaderObject;
  std::string getStringShaderSource();
  GLenum ShaderTypeParameter;
 public:
  //createShader(int shaderType,std::vector<std::string> shaderVector);
  createShader(GLenum shaderType, std::string shaderVector);

  UIx64 createShaderObject();
  void deleteShaderObject();
  ~createShader();
};