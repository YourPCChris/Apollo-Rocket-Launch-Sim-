
#include <iostream>
#include <memory>
#include "window.h"
#include "rocket.h"
#include "weather.h"

int main()
{
    //std::cout << "We Ball" << std::endl;
    
    Window w = Window(1000, 800);
    std::string launchText = "Boosters 1";
    std::string resetRocketText = "Reset Rocket 2";
    w.addButton(launchText);
    w.addButton(resetRocketText);

    InitWindow(w.getWidth(), w.getHeight(), "Apollo");

    Camera3D camera = {0};
    camera.position = (Vector3){200.0f,200.0f,200.0f};
    camera.target = (Vector3){0.0f,0.0f,0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();
    SetTargetFPS(60);

    std::unique_ptr<Rocket> rocket = std::make_unique<Rocket>();
    std::unique_ptr<ForceManagement> fm = std::make_unique<ForceManagement>();
    

    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_ONE)) (rocket->getBoosterOn()) ? rocket->pause() : rocket->launch();
        if (IsKeyPressed(KEY_TWO)) rocket->resetPos();
        if (IsKeyPressed(KEY_THREE)) (fm->wind->getIsOn()) ? (fm->wind->turnOff()) : (fm->wind->turnOn());

        BeginDrawing();
        w.display();

        //fm->update();
        BeginMode3D(camera);
        //DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(300, 1.0f);
        rocket->update(fm->getXForce(), fm->getYForce(), fm->getZForce());
        rocket->display();
        EndMode3D();
        EndDrawing();

        UpdateCamera(&camera, CAMERA_FREE);
    }

    CloseWindow();
    return 0;
}
