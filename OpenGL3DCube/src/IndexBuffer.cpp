#include "../include/IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count):count(count) {
    glGenBuffers(1,&id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,GL_STATIC_DRAW);
}
unsigned int IndexBuffer::getCount() const { return count;}