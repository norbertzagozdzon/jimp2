#include "../include/VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
}

void VertexArray::vertexAttribPtrf(unsigned int index, unsigned int size, size_t stride, const void* ptr) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, ptr);
}