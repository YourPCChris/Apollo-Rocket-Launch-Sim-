#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "raylib.h"


class Button
{
    float x, 
          y,
        width,
        height,
        fontSize;
    Color color;
    std::unique_ptr<Rectangle> rec;
    const char* text;

    public:
    Button(const char* newText, float newX, float newY, float newWidth=160, float newHeight=60);
    void display();
    Rectangle getRec();
    float getHeight();
    float getX();
    float getY();
};
