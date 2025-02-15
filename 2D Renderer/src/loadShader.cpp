#include"../header/loadShader.hpp"

//load Shader files
loadShader::loadShader(std::string ShaderFileName)
    : ShaderFileName(ShaderFileName)
{
    //set file exceptions
    //std::ifstream::eofbit
    //std::fstream::failbit |
  //fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
    fileStream.open(ShaderFileName);
      while (std::getline(fileStream, shaderLine)) {
      shaderFileContent.push_back(shaderLine);
        LOGINFO<std::string>(shaderLine);
      }

      //second version of loading string using sstream
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