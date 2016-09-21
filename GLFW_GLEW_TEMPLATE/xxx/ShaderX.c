//
//  ShaderX.c
//  xxx
//
//  Created by Vincent Smithers on 9/21/16.
//  Copyright © 2016 Vince Smithers. All rights reserved.
//

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(position, 1.0f);
    ourColor = color;
}
