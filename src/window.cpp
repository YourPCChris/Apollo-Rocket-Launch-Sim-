
#include "window.h"

Window::Window(int newWidth,int newHeight) : width(newWidth), height(newHeight) {}
void Window::display()
{
    ClearBackground(RAYWHITE);
    if (buttons.size() > 0){
        for (auto& button : buttons)
        {
            button->display();
        }
    }

    //rocket->display();
}
void Window::addButton(std::string newText)
{
    int newY = (buttons.size() == 0) ? (25) : (25*((buttons.size()/10)+1));
    buttons.push_back(std::make_unique<Button>(newText.c_str(), 20, newY));
}


//------------------Gets & Sets------------------------------

Color Window::getBGColor() { return bgColor;}
int Window::getWidth() { return width;}
int Window::getHeight() { return height;}
