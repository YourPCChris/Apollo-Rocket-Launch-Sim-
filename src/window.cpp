
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
void Window::addButton(std::string newText){}


//------------------Gets & Sets------------------------------

Color Window::getBGColor() { return bgColor;}
int Window::getWidth() { return width;}
int Window::getHeight() { return height;}
