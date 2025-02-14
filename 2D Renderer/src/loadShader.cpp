#include"../header/loadShader.hpp"

//load Shader files
loadShader::loadShader(std::string ShaderFileName)
    : ShaderFileName(ShaderFileName)
{
    //set file exceptions
  fileStream.exceptions(std::fstream::failbit | std::ifstream::badbit |
                        std::ifstream::eofbit);
    try {
    fileStream.open(ShaderFileName);
      while (fileStream >> shaderLine) {
      shaderFileContent.push_back(shaderLine);
      }

    } catch (const std::ifstream::failure &e) {
      LOGERROR<std::string>(e.what());
    }
}

std::vector<std::string> loadShader::returnShaderFileContent() const {
  return shaderFileContent;
}

loadShader::~loadShader() { 
    fileStream.close();
}