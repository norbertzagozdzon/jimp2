#ifndef OPENGL3DCUBE_VERTEXBUFFER_H
#define OPENGL3DCUBE_VERTEXBUFFER_H

#define GLEW_STATIC
#include<GL/glew.h>

class VertexBuffer {
private:
    unsigned int id;
public:
    VertexBuffer(const void *data, unsigned int size);
};

#endif //OPENGL3DCUBE_VERTEXBUFFER_H
