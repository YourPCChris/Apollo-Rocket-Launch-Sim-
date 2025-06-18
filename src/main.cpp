
#include <iostream>
#include <memory>
#include "window.h"
#include "rocket.h"

int main()
{
    //std::cout << "We Ball" << std::endl;
    
    Window w = Window(1000, 800);
    w.addButton("Launch Rocket 1 ");
    w.addButton("Pause Rocket 0 ");
    w.addButton("Reset Rocket");
    
    InitWindow(w.getWidth(), w.getHeight(), "Apollo");

    Camera3D camera = {0};
    camera.position = (Vector3){100.0f,100.0f,100.0f};
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
        if (IsKeyPressed(KEY_ZERO)) rocket->pause();
        if (IsKeyPressed(KEY_TWO)) rocket->resetPos();

        BeginDrawing();
        w.display();

        BeginMode3D(camera);
        //DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(300, 1.0f);
        rocket->update();
        rocket->display();
        EndMode3D();
        EndDrawing();

        UpdateCamera(&camera, CAMERA_FREE);
    }

    CloseWindow();
    return 0;
}
