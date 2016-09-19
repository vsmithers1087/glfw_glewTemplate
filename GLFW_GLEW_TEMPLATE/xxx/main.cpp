//
//  main.cpp
//  xxx
//
//  Created by Vincent Smithers on 9/17/16.
//  Copyright © 2016 Vince Smithers. All rights reserved.
//

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


int main() {
    std::cout << "Starting GLFW context" << std::endl;
    
    //glew init
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    
    if (!glfwInit()) {
        std::cout<< "Couldn't init glfw" << std::endl;
        exit(1);
    }

    //create window
    
    GLFWwindow *window;
    glewExperimental = GL_TRUE;
    
    window = glfwCreateWindow(900, 640.0, "Test_Window", NULL, NULL);
    
    if (!window) {
        std::cout<< "Couldn't create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(window, key_callback);
    
    //set viewport.
    
    glfwMakeContextCurrent(window);
    
    int width, height;
    
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        std::cout<< "ESC Pressed" << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}


