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
#include"include/Model.h"

float verticesCube[] = {
        -0.5, 0.5, 0.5, 1.0, 0.0, 1.0,	// Front Top Left
        0.5,  0.5, 0.5, 1.0, 0.0, 0.0,	// Front Top Right
        0.5, -0.5, 0.5, 0.0, 1.0, 0.0,	// Front Bottom Right
        -0.5,-0.5, 0.5, 0.0, 0.0, 1.0,	// Front Bottom Left
        -0.5, 0.5,-0.5, 1.0, 1.0, 0.0,	// Back Top Left
        0.5,  0.5,-0.5, 1.0, 0.0, 0.0,	// Back Top Right
        0.5, -0.5,-0.5, 1.0, 1.0, 0.0,	// Back Bottom Right
        -0.5,-0.5,-0.5, 0.0, 0.0, 1.0,	// Back Bottom Left
};

unsigned int indicesCube[] = {
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

float verticesPyramid[] = {
        -0.5f, -0.5f, -0.5f, 0.0, 0.0, 1.0, // v0
        0.5f, -0.5f, -0.5f, 0.0, 1.0, 0.0, // v1
        0.5f, -0.5f, 0.5f, 0.0, 0.0, 1.0, // v2
        -0.5f, -0.5f, 0.5f, 0.0, 1.0, 0.0, // v3
        0.f, 0.5f, 0.f, 1.0, 0.0, 0.0, // v4

};

unsigned int indicesPyramid[] {
    3,2,4, // front
    2,1,4, // left
    1,0,4, // right
    0,3,4, // back
    0,1,2,
    2,3,0, // bottom
};

int main() {

    Model cube(verticesCube,indicesCube,sizeof(verticesCube),sizeof(indicesCube));
    Model pyramid(verticesPyramid,indicesPyramid,sizeof(verticesPyramid),sizeof(indicesPyramid));
    Model model;

    while(true) {
        unsigned short choice;
        std::cout <<"Select the Model:"<<std::endl<<"1. Cube" << std::endl << "2. Pyramid" << std::endl << "Your choice?: ";
        std::cin >> choice;

        if (choice == 1) {
            model = cube;
            break;
        }
        else if (choice == 2) {
            model = pyramid;
            break;
        }
        else {
            std::cout << "There's no choice like that. Type again..." << std::endl;
        }
    }

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

    unsigned int indCount = model.getSizeIndices()/sizeof(GLuint);
    unsigned int verSize = model.getSizeVertices();

    VertexArray vao;
    Shader sh("../shaders/DefVertex.shader","../shaders/DefFragment.shader");
    sh.bind();
    Matrix matrix;
    matrix.transplate(0.f,-0.1f,0.f);
    sh.setUniformMatrix4fv("Model",1,matrix);

    VertexBuffer vbo(model.getVertices(),verSize);
    IndexBuffer ibo(model.getIndices(),indCount);
    vao.vertexAttribPtrf(0,3,6*sizeof(GLfloat),(const void*)0);
    vao.vertexAttribPtrf(1,3,6*sizeof(GLfloat),(const void*)(3*sizeof(GLfloat)));

    Renderer rend;
    rend.enableDepth();

    float chY = 0.005f;
    int time=0;

    while (!glfwWindowShouldClose(window))
    {
        rend.clear();
        rend.draw(indCount);
        matrix.rotate(0.3f,1.f,1.f,1.f);
        matrix.transplate(0.f,chY,0.f);
        sh.setUniformMatrix4fv("Model",1,matrix);

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