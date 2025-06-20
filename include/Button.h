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
    std::string text;

    public:
    Button(std::string newText, float newX, float newY, float newWidth=200, float newHeight=60);
    void display();
    Rectangle getRec();
    float getHeight();
    float getX();
    float getY();
};
