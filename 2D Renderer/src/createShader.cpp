#include"../header/createShader.hpp"

//createShader::createShader(int shaderType,std::vector<std::string>shaderVector) :ShaderTypeParameter(shaderType) {
createShader::createShader(GLenum shaderType, std::string shaderVector)
    : ShaderTypeParameter(shaderType), stringShaderSource(shaderVector) {

		
}
 
std::string createShader::getStringShaderSource() { 
    return stringShaderSource;
}

UIx64 createShader::createShaderObject() {

  std::string shaderSource = getStringShaderSource();  // Store the shader source safely
  const char* tempStore = shaderSource.c_str();
  GLenum shaderType =
      ((ShaderTypeParameter == static_cast<GLenum>(SHADERTYPE::VERTEX))
           ? static_cast<GLenum>(SHADERTYPE::VERTEX)
           : static_cast<GLenum>(SHADERTYPE::FRAGMENT));
  shaderObject = glCreateShader(shaderType);
  glShaderSource(shaderObject, 1, &tempStore, NULL);
  glCompileShader(shaderObject);

  // Error handling
  int signal;
  char errorInfo[512];
  glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &signal);
  if (!signal) {
    glGetShaderInfoLog(shaderObject, 512, NULL, errorInfo);

    std::string ErrorValue = "Error in: ";
    ErrorValue += (shaderType == GL_VERTEX_SHADER) ? "Vertex Shader - "
                                                   : "Fragment Shader - ";
    ErrorValue.append(errorInfo);

    LOGERROR<std::string>(ErrorValue);
    std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"<< ErrorValue << std::endl;

    //Print shader source for debugging
    std::cerr << "Shader Source:\n" << stringShaderSource << std::endl;

    exit(EXIT_FAILURE);
  }

  return shaderObject;
}

void createShader::deleteShaderObject() { 
    glDeleteShader(shaderObject); 
}

createShader::~createShader() {}