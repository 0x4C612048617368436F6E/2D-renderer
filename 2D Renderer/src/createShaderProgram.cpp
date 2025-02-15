#include"../header/createShaderProgram.hpp"

createShaderProgram::createShaderProgram() {

}
UIx64 createShaderProgram::shaderProgram() {
	//will make use of the shaders here
  UIx64 programObject;
  programObject = glCreateProgram();
  //instantiate both object to load Vertex and Fragment
  std::string shaderPathName = "C:/Users/benja/Desktop/2D Renderer/2D Renderer/resources/fragmentShader.frag";
  std::string fragmentPathName = "C:/Users/benja/Desktop/2D Renderer/2D Renderer/resources/vertexShader.vert";
  loadShader loadVertexShader(shaderPathName);
  loadShader loadFragmentShader(fragmentPathName);
  //instantiate both Shader and Fragment shader here
  const char* vertexStore =
      "#version 460 core\n"
      "layout(location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";
  const char* fragmentStore ="#version 460 core\n"
      "out vec4 Fragment;\n"
      "void main()\n"
      "{\n"
      "Fragment = vec4(0.0, 1.0, 0.0, 1.0);\n"
      "}\0";
  createShader VertexShader(GL_VERTEX_SHADER, vertexStore);
      //loadVertexShader.returnShaderFileContentAsStringStream());
  createShader FragmentShader(GL_FRAGMENT_SHADER,fragmentStore);
      //loadFragmentShader.returnShaderFileContentAsStringStream());
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
  //VertexShader.deleteShaderObject();
  //FragmentShader.deleteShaderObject();
  //use program
  return programObject;
}

createShaderProgram::~createShaderProgram() {

}