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
#include <math.h>
#include "SOIL.h"
#include "ShaderXXX.h"


//MARK: key callback declaration
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

//MARK: main
int main() {
    //MARK: glew init
    glfwInit();
    
    if (!glfwInit()) {
        std::cout<< "Couldn't init glfw" << std::endl;
        exit(1);
    }

    std::cout << "Starting GLFW context" << std::endl;
    
    //MARK: set required options for glfw window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glewExperimental = GL_TRUE;
    
    //MARK: create window
 
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Test_Window", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    if (!window) {
        std::cout<< "Couldn't create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    //MARK: set callback
    glfwSetKeyCallback(window, key_callback);
    
    //MARK: glew init
    glewInit();
    
    //MARK: set viewport.
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    //MARK: our shader
    
    Shader ourShader("VertexShader.vs", "FragmentShader.fr");
    
    //MARK: vertices
    GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
        1.f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   4.0f, 4.0f,   // Top Right
        1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   4.0f, -1.0f,   // Bottom Right
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   -1.0f, 0.0f,   // Bottom Left
        -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   -1.0f, 4.0f    // Top Left
    };
    
    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };
    
    //MARK: linking vertex attributes
    GLuint VAO, VBO, EBO;
    
    //MARK: bind vertex array object then bind and set vertex buffers and attribute pointers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    
    //MARK: position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    //MARK: color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)(3* sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    //MARK: texCord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    
    
    //MARK: undbind array buffers
    glBindVertexArray(0);
    
    //MARK: Texture 1 generate and bind
    GLuint texture1;
    GLuint texture2;
    
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    
    //MARK:Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // MARK: load and create image texture
    int widthX, heightX;
    unsigned char* image = SOIL_load_image("turtles.jpg", &widthX, &heightX, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthX, heightX, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    
    //MARK: unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
  
    //MARK: texture 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image = SOIL_load_image("turtlesTex.jpg", &widthX, &heightX, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthX, heightX, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    
    //MARK: "RUNTIME LOOP"
    while (!glfwWindowShouldClose(window)) {
        //MARK: check for events
        glfwPollEvents();
        
        //MARK: render
        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        
        //MARK: clear color buffer
        glClear(GL_COLOR_BUFFER_BIT);
        
        ourShader.Use();
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);
        //MARK: draw triangle
//        ourShader.Use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        //MARK: swap screen buffers
        glfwSwapBuffers(window);
    }
    //MARK: deallocate once loop exits
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    
    //MARK: terminate glfw
    glfwTerminate();
    
    return 0;
}

//MARK: keycallback defined
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        std::cout<< "ESC Pressed" << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}


