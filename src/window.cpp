
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
    float newY = (buttons.size() == 0) ? (25) : (buttons.back()->getHeight()+buttons.back()->getRec().y + 10);
    //std::cout << "Size of buttons is: " << buttons.size() << std::endl;
    buttons.push_back(std::make_unique<Button>(newText.c_str(), 20, newY));
    //std::cout << "New Button is at -> " <<  buttons.back()->getX() << " : " << buttons.back()->getY() << std::endl;
}


//------------------Gets & Sets------------------------------

Color Window::getBGColor() { return bgColor;}
int Window::getWidth() { return width;}
int Window::getHeight() { return height;}
