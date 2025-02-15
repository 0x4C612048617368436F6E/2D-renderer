#include"../header/createShaderProgram.hpp"

createShaderProgram::createShaderProgram() {

}
UIx64 createShaderProgram::shaderProgram() {
	//will make use of the shaders here
  UIx64 programObject;
  programObject = glCreateProgram();
  //instantiate both object to load Vertex and Fragment
  static std::string vertexPathName = "C:/Users/benja/Desktop/2D Renderer/2D Renderer/resources/vertexShader.glsl";
  static std::string fragmentPathName = "C:/Users/benja/Desktop/2D Renderer/2D Renderer/resources/fragmentShader.glsl";
  loadShader loadVertexShader(vertexPathName);
  loadShader loadFragmentShader(fragmentPathName);
  //instantiate both Shader and Fragment shader here
  createShader VertexShader(GL_VERTEX_SHADER, loadVertexShader.returnShaderFileContentAsStringStream());
  createShader FragmentShader(GL_FRAGMENT_SHADER,loadFragmentShader.returnShaderFileContentAsStringStream());
  glAttachShader(programObject,VertexShader.createShaderObject());
  glAttachShader(programObject, FragmentShader.createShaderObject());

  //lets link the shaders up to a single program
  glLinkProgram(programObject);
  int signal;
  char errorInfo[512];
  glGetProgramiv(programObject, GL_LINK_STATUS, &signal);
  if (signal == GL_FALSE) {
    glGetProgramInfoLog(programObject, 512, NULL, errorInfo);
    LOGERROR<std::string>(errorInfo);
    exit(EXIT_FAILURE);
  }
  //delete shaders ... create helper in the shader class
  VertexShader.deleteShaderObject();
  FragmentShader.deleteShaderObject();
  //use program
  return programObject;
}

createShaderProgram::~createShaderProgram() {
    
}