#ifndef OPENGL3DCUBE_SHADER_H
#define OPENGL3DCUBE_SHADER_H
#define GLEW_STATIC
#include <GL/glew.h>

#include<fstream>
#include <iostream>
#include "Matrix.h"

class Shader {
private:
    std::string fp1;
    std::string fp2;
    unsigned int id;
public:
    Shader(const std::string& fpVertex, const std::string& fpFragment);
    void bind() const;
    void unbind() const;
    std::string ParseShader(const std::string& filepath);
    unsigned int compileShader(unsigned int type, const std::string& source);
    unsigned int createShader(const std::string& vsSource, const std::string& fsSource);
    void setUniformMatrix4fv(const std::string &name, int count, Matrix matrix);
    void setUniform3f(const std::string &name, float v0, float v1, float v2);
};

#endif //OPENGL3DCUBE_SHADER_H
