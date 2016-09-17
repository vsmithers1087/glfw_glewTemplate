//
//  main.cpp
//  xxx
//
//  Created by Vincent Smithers on 9/17/16.
//  Copyright © 2016 Vince Smithers. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void render(void){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);{
        glColor3f(1, 0, 0);
        glVertex2f(0, 0.5);
        glColor3f(0, 1, 0);
        glVertex2f(-0.5, -0.5);
        glColor3f(0, 0, 1);
        glVertex2f(0.5, -0.5);
    }
    
    glEnd();
}

int main(int argc, const char * argv[]) {

    GLFWwindow *window;
    
    if (!glfwInit()) {
        exit(1);
    }
    
    window = glfwCreateWindow(900, 640.0, "Test", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}
