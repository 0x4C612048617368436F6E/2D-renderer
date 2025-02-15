#include"../header/renderObject.hpp"

renderObject::renderObject() {

}

void renderObject::drawTraingle(size_t X1, size_t Y1, size_t X2, size_t Y2) {
	//find a way to normalise (Do later)
	 //create new instance of 'createShaderProgram'
     
	//first create buffer object in GPU and store the stuff there
        glGenVertexArrays(1, &TriangleVAO);
        glBindVertexArray(TriangleVAO);

		//create TriangleVBO
        glGenBuffers(1, &TriangleVBO);
        glBindBuffer(GL_ARRAY_BUFFER, TriangleVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertexAttributes),
                     triangleVertexAttributes, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              (void*)0);
        glEnableVertexAttribArray(0);
        //glBindBuffer(GL_ARRAY_BUFFER, 0);
        //glBindVertexArray(0);
}

void renderObject::activateTriagleVAO() const {
  glBindVertexArray(TriangleVAO);

}

renderObject::~renderObject() {
    //out of scope
}