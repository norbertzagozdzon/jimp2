#include "../include/Renderer.h"

void Renderer::clear() {
    glClearColor(0.f,0.f,0.f,1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(unsigned int count) {
    glDrawElements(GL_TRIANGLES,count,GL_UNSIGNED_INT,nullptr);
}

void Renderer::enableDepth() {
    glEnable(GL_DEPTH_TEST);
}