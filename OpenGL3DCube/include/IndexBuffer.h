#ifndef OPENGL3DCUBE_INDEXBUFFER_H
#define OPENGL3DCUBE_INDEXBUFFER_H

#define GLEW_STATIC
#include<GL/glew.h>

class IndexBuffer {
private:
    unsigned int id;
    unsigned int count;
public:
    IndexBuffer(const unsigned int *data, unsigned int count);
    unsigned int getCount() const;
};

#endif //OPENGL3DCUBE_INDEXBUFFER_H
