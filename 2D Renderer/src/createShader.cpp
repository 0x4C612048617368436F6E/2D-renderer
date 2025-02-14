#include"../header/createShader.hpp"

createShader::createShader(int shaderType,std::vector<std::string>shaderVector) {
	//convert vector to string
        for (std::string value : shaderVector) {
             stringShaderSource.append(value);
		}
		
}

std::string createShader::getStringShaderSource() { 
    return stringShaderSource;
}

UIx64 createShader::createShaderObject() {
  const char* tempStore = getStringShaderSource().c_str();

  // get the type of shader to create
  int shaderType =
      static_cast<int>((shaderType == static_cast<int>(SHADERTYPE::VERTEX))
                           ? SHADERTYPE::VERTEX
                           : SHADERTYPE::FRAGMENT);
  // create shader objects
  UIx64 shaderObject;
  shaderObject = glCreateShader(shaderType);
  glShaderSource(shaderObject, 1, &tempStore, NULL);
  glCompileShader(shaderObject);
  // do some error handling
  int signal;
  char errorInfo[512];
  glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &signal);
  if (signal == GL_FALSE) {
    // get the actual error
    glGetShaderInfoLog(shaderObject, 512, NULL, errorInfo);
    LOGERROR<std::string>(errorInfo);
    exit(EXIT_FAILURE);
  }
  // just return the shader object so it can be used
  return shaderObject;
}

createShader::~createShader() {}