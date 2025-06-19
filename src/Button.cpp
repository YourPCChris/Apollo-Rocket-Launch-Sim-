
#include "Button.h"
#include "raylib.h"

//-------------------------Button___________________________
Button::Button(std::string newText, float newX, float newY, float newWidth, float newHeight)
:text(newText), x(newX), y(newY), width(newWidth), height(newHeight), color(DARKGRAY)
{
    rec = std::make_unique<Rectangle>(Rectangle{x, y, width, height});
    fontSize = height*0.33;
}

void Button::display()
{
    DrawRectangleRec(*rec, DARKGRAY);
    int textWidth = MeasureText(text.c_str(), fontSize);
    float textX = x + (width - textWidth) / 2;
    float textY = y + (height - fontSize) / 2;
    DrawText(text.c_str(), textX, textY, fontSize, BLACK);
}

float Button::getHeight() { return height;}   
Rectangle Button::getRec() { return *rec;}
float Button::getX() { return x;}
float Button::getY() { return y;}
