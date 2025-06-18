#pragma once 

#include <vector>
#include <memory>
#include "raylib.h"
#include "rocket.h"
#include "Button.h"

class Window
{
    std::vector<std::unique_ptr<Button>> buttons;
    int 
        width,
        height;
    Color bgColor;

    public:

    Window(int newWidth, int newHeight);
    int getWidth();
    int getHeight();
    Color getBGColor();
    void display();
    void addButton(std::string newText);
};
