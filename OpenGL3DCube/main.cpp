#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include<iostream>
#include"include/VertexArray.h"
#include"include/Shader.h"
#include"include/VertexBuffer.h"
#include"include/IndexBuffer.h"
#include"include/Matrix.h"
#include"include/Renderer.h"

float vertices[] = {
        -0.5, 0.5, 0.5, 1.0, 0.0, 1.0,	// Front Top Left
        0.5,  0.5, 0.5, 1.0, 0.0, 0.0,	// Front Top Right
        0.5, -0.5, 0.5, 0.0, 1.0, 0.0,	// Front Bottom Right
        -0.5,-0.5, 0.5, 0.0, 0.0, 1.0,	// Front Bottom Left
        -0.5, 0.5,-0.5, 1.0, 1.0, 0.0,	// Back Top Left
        0.5,  0.5,-0.5, 1.0, 0.0, 0.0,	// Back Top Right
        0.5, -0.5,-0.5, 1.0, 1.0, 0.0,	// Back Bottom Right
        -0.5,-0.5,-0.5, 0.0, 0.0, 1.0,	// Back Bottom Left
};

unsigned int indices[] = {
     0,3,2,
     2,1,0, //front
     4,7,6,
     6,5,4, // back
     4,7,3,
     3,0,4, // left
     1,2,6,
     6,5,1, // right
     4,0,1,
     1,5,4, // top
     7,3,2,
     2,6,7, // bottom
};

int main() {
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(600, 600, "OpenGL3DCube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();

    VertexArray vao;
    Shader sh("../shaders/DefVertex.shader","../shaders/DefFragment.shader");
    sh.bind();
    Matrix model;
    model.transplate(0.f,-0.1f,0.f);
    sh.setUniformMatrix4fv("Model",1,model);
    VertexBuffer vbo(vertices,sizeof(vertices));
    IndexBuffer ibo(indices,36);
    vao.vertexAttribPtrf(0,3,6*sizeof(GLfloat),(const void*)0);
    vao.vertexAttribPtrf(1,3,6*sizeof(GLfloat),(const void*)(3*sizeof(GLfloat)));

    Renderer rend;
    rend.enableDepth();

    float chY = 0.005f;
    int time=0;

    while (!glfwWindowShouldClose(window))
    {
        rend.clear();
        rend.draw(36);
        model.rotate(0.3f,1.f,1.f,1.f);
        model.transplate(0.f,chY,0.f);
        sh.setUniformMatrix4fv("Model",1,model);

        if (time>=50) {
            if(chY==0.005f) {
                chY=-0.005f;
            }
            else {
                chY = 0.005f;
            }
            time=0;
        }
        time++;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}