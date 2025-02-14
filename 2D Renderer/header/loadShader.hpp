#pragma once
#include"../header/common.hpp"
class loadShader {
 private:
  std::string ShaderFileName;
  std::ifstream fileStream;
  std::string shaderLine;
  std::vector<std::string> shaderFileContent;
 public:
  loadShader(std::string ShaderFileName);
  std::vector<std::string> returnShaderFileContent() const;
  ~loadShader();
};