#include"../header/renderObject.hpp"

renderObject::renderObject() {

}

void renderObject::drawTraingle(size_t X1, size_t Y1, size_t X2, size_t Y2) {
	//find a way to normalise (Do later)
	 
	//first create buffer object in GPU and store the stuff there
        UIx64 VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

		//create VBO
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertexAttributes),
                     triangleVertexAttributes, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT),
                              0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
}