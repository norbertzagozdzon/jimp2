#include"../include/Model.h"

Model::Model(float *vertices, unsigned int *indices,unsigned int sizeVertices, unsigned int sizeIndices): vertices(vertices), indices(indices), sizeVertices(sizeVertices), sizeIndices(sizeIndices) {}
float *Model::getVertices() {return vertices;}
unsigned int *Model::getIndices() {return indices;}
unsigned int Model::getSizeVertices() {return sizeVertices;}
unsigned int Model::getSizeIndices() {return sizeIndices;}