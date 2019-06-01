#ifndef OPENGL3DCUBE_VERTEXARRAY_H
#define OPENGL3DCUBE_VERTEXARRAY_H

#define GLEW_STATIC
#include <GL/glew.h>

class VertexArray {
private:
    unsigned int id;
public:
    VertexArray();
    void vertexAttribPtrf(unsigned int index, unsigned int size, size_t stride, const void* ptr);
};

#endif //OPENGL3DCUBE_VERTEXARRAY_H
