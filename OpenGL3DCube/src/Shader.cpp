#include "../include/Shader.h"

Shader::Shader(const std::string& fpVertex, const std::string& fpFragment) {
    std::string vertexSource = ParseShader(fpVertex);
    std::string fragmentSource = ParseShader(fpFragment);
    id = createShader(vertexSource,fragmentSource);
}

void Shader::bind() const {
    glUseProgram(id);
}
void Shader::unbind() const {
    glUseProgram(0);
}

std::string Shader::ParseShader(const std::string &filepath) {
    std::ifstream stream(filepath);
    if(stream.good()) {
        std::string res;
        std::string line;
        while(getline(stream,line)) {
            res+=line;
            res+="\n";
        }
        return res;
    }
    else {
        return "";
    }
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source) {
        unsigned int index = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(index,1,&src, nullptr);
        glCompileShader(index);

        //error handlin
        int result;
        glGetShaderiv(index,GL_COMPILE_STATUS,&result);
        if(result==GL_FALSE) {
            std::cout << "error" << std::endl;
            int length;
            glGetShaderiv(index, GL_INFO_LOG_LENGTH, &length);
            char *message = new char[length];
            glGetShaderInfoLog(index, length, &length, message);
            std::cout << message;
        }
        return index;
}

unsigned int Shader::createShader(const std::string& vsSource, const std::string& fsSource) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER,vsSource);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER,fsSource);
    glAttachShader(program,vs);
    glAttachShader(program,fs);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

void Shader::setUniformMatrix4fv(const std::string &name, int count, Matrix matrix) {
    glUniformMatrix4fv(glGetUniformLocation(id,name.c_str()),count,GL_FALSE,glm::value_ptr(matrix.getModel()));
}
void Shader::setUniform3f(const std::string &name, float v0, float v1, float v2) {
    glUniform3f(glGetUniformLocation(id,name.c_str()),v0,v1,v2);
}