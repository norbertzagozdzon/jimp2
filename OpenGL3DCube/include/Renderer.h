#ifndef OPENGL3DCUBE_RENDERER_H
#define OPENGL3DCUBE_RENDERER_H
#define GLEW_STATIC
#include <GL/glew.h>


class Renderer {
public:
    void clear();
    void draw(unsigned int count);
    void enableDepth();
};

#endif //OPENGL3DCUBE_RENDERER_H
