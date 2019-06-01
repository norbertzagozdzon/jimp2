#include "../include/Matrix.h"

Matrix::Matrix():model(glm::mat4(1.f)) {}

void Matrix::transplate(float x, float y, float z) {
    model = glm::translate(model,glm::vec3(x,y,z));
}

void Matrix::rotate(float rad, float x, float y, float z) {
    model = glm::rotate(model,glm::radians(rad),glm::vec3(x,y,z));
}

glm::mat4 Matrix::getModel() {return model;}