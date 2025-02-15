#include"../header/loadShader.hpp"

//load Shader files
loadShader::loadShader(std::string ShaderFileName)
    : ShaderFileName(ShaderFileName)
{

  fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
    fileStream.open(ShaderFileName);

      stringStream << fileStream.rdbuf();
      stringStreamShaderSourceCode = stringStream.str();
    } catch (const std::ifstream::failure &e) {
      LOGERROR<std::string>(e.what());
    }
}

std::vector<std::string> loadShader::returnShaderFileContent() const {
  return shaderFileContent;
}
std::string loadShader::returnShaderFileContentAsStringStream() const {
  return stringStreamShaderSourceCode;
}



loadShader::~loadShader() { 
    fileStream.close();
}