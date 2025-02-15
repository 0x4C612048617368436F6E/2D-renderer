#pragma once
#include"../header/common.hpp"
class loadShader {
 private:
  std::string ShaderFileName;
  std::ifstream fileStream;
  std::string shaderLine;
  std::stringstream stringStream;
  std::string stringStreamShaderSourceCode;
  std::vector<std::string> shaderFileContent;
 public:
  loadShader(std::string ShaderFileName);
  std::vector<std::string> returnShaderFileContent() const;
  std::string returnShaderFileContentAsStringStream() const;
  ~loadShader();
};