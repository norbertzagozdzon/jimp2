cmake_minimum_required(VERSION 3.13)
project(OpenGL3DCube)

set(CMAKE_CXX_STANDARD 14)
include_directories(libs/GLFW/include libs/GLEW/include libs/glm)
link_directories(libs/GLFW/lib-mingw libs/GLEW/lib/Release/Win32)
find_package(OpenGL REQUIRED)
add_executable(OpenGL3DCube main.cpp include/VertexArray.h include/Shader.h include/VertexBuffer.h include/IndexBuffer.h include/Matrix.h include/Renderer.h src/VertexArray.cpp src/Shader.cpp src/VertexBuffer.cpp src/IndexBuffer.cpp src/Matrix.cpp src/Renderer.cpp)
target_link_libraries(OpenGL3DCube glew32s opengl32 kernel32 glfw3)