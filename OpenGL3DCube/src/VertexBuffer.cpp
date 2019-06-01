#include "../include/VertexBuffer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    glGenBuffers(1,&id);
    glBindBuffer(GL_ARRAY_BUFFER,id);
    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}