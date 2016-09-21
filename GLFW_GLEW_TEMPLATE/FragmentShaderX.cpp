//
//  FragmentShaderX.cpp
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

const GLchar* fragmentShaderSource = "#version 330 core\n"
"in vec3 ourColor;\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(ourColor, 1.0f);\n"
"}\n\0";
