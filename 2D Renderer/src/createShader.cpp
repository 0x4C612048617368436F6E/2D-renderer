#include"../header/createShader.hpp"

//createShader::createShader(int shaderType,std::vector<std::string>shaderVector) :ShaderTypeParameter(shaderType) {
createShader::createShader(GLenum shaderType, std::string shaderVector)
    : ShaderTypeParameter(shaderType), stringShaderSource(shaderVector) {
    //convert vector to string
  /* for (std::string value : shaderVector) {
             stringShaderSource.append(value);
          stringShaderSource += "\n";
		}*/
		
}
 
std::string createShader::getStringShaderSource() { 
    return stringShaderSource;
}

UIx64 createShader::createShaderObject() {
  /* size_t currentRange = 10;
  char* tempStore = (char *)malloc(currentRange*sizeof(char));
  if (!tempStore) {
    LOGERROR<std::string>("Unable to allocate memory");
    exit(EXIT_FAILURE);
  }
  //= getStringShaderSource().c_str();
  //tempStore[strlen(tempStore)] = '/0';
  size_t pointer = 0;
  for (int i = 0; i < getStringShaderSource().size(); i++) {
    if (pointer >= currentRange-1) {
      currentRange *= 2;
      tempStore = (char*)realloc(tempStore,currentRange * sizeof(char));
      if (!tempStore) {
        LOGERROR<std::string>("Unable to allocate memory");
        exit(EXIT_FAILURE);
      }
    } else {
      tempStore[pointer++] = getStringShaderSource()[i];
    }
  }
  tempStore[pointer] = '\0';*/
  //std::string shaderSource = getStringShaderSource();  // Store the shader source safely
  const char* tempStore = stringShaderSource.c_str();  // shaderSource.c_str();  // Get pointer to C-string

  GLenum shaderType = (ShaderTypeParameter == GL_VERTEX_SHADER)
                          ? GL_VERTEX_SHADER
                          : GL_FRAGMENT_SHADER;

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
    std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"
              << errorInfo << std::endl;

    // Print shader source for debugging
    //std::cerr << "Shader Source:\n" << shaderSource << std::endl;

    exit(EXIT_FAILURE);
  }

  return shaderObject;
}

void createShader::deleteShaderObject() { 
    glDeleteShader(shaderObject); 
}

createShader::~createShader() {}