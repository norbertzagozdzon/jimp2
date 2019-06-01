#ifndef OPENGL3DCUBE_MATRIX_H
#define OPENGL3DCUBE_MATRIX_H

#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

class Matrix {
private:
    glm::mat4 model;
public:
    Matrix();
    void transplate(float x, float y, float z);
    void rotate(float rad, float x, float y, float z);

    glm::mat4 getModel();

};

#endif //OPENGL3DCUBE_MATRIX_H
