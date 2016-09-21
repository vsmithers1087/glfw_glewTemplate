//
//  VertexShaderX.cpp
//  xxx
//
//  Created by Vincent Smithers on 9/21/16.
//  Copyright © 2016 Vince Smithers. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position, 1.0);\n"
"ourColor = color;\n"
"}\0";
