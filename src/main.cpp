
#include <iostream>
#include <memory>
#include "window.h"
#include "rocket.h"

int main()
{
    //std::cout << "We Ball" << std::endl;
    
    Window w = Window(1000, 800);
    std::string launchText = "Launch Rocket (1)";
    w.addButton(launchText);
    
    InitWindow(w.getWidth(), w.getHeight(), "Apollo");

    Camera3D camera = {0};
    camera.position = (Vector3){10.0f,10.0f,10.0f};
    camera.target = (Vector3){0.0f,0.0f,0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();
    SetTargetFPS(60);

    std::unique_ptr<Rocket> rocket = std::make_unique<Rocket>();
    Vector3 startPos = camera.position;
    Vector3 targetPos = camera.target;
    
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_ONE)) rocket->launch();

        BeginDrawing();
        w.display();

        BeginMode3D(camera);
        //DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(10, 1.0f);
        rocket->update();
        rocket->display();
        EndMode3D();
        EndDrawing();

        UpdateCamera(&camera, CAMERA_FREE);
    }

    CloseWindow();
    return 0;
}
