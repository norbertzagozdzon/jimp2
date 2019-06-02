#ifndef OPENGL3DCUBE_MODEL_H
#define OPENGL3DCUBE_MODEL_H

class Model {
private:
    float *vertices;
    unsigned int *indices;
    unsigned int sizeVertices;
    unsigned int sizeIndices;
public:
    Model() = default;
    Model(float *vertices, unsigned int *indices,unsigned int sizeVertices, unsigned int sizeIndices);
    float *getVertices();
    unsigned int *getIndices();
    unsigned int getSizeVertices();
    unsigned int getSizeIndices();
};

#endif //OPENGL3DCUBE_MODEL_H
