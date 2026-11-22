#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <cmath>

using namespace std;

int main() {
    //some of this code is from the "3d camera free" example on raylib

    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Algorithms");
    Camera3D camera = { 0 };
    camera.position = (Vector3) { 50.0f, 15.0f, 0.0f }; //position (x,y,z), the Y axis points upwards
    camera.target = (Vector3) { 0.0f, 0.0f, 0.0f }; //looking at
    camera.up = (Vector3) { 0.0f, 1.0f, 0.0f }; //pitch(?)
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);
    
    while(!WindowShouldClose()) {
        //UpdateCamera(&camera, CAMERA_FREE);   //-------------this lets you fly around and move around in 3d
        float dt = GetFrameTime();

        BeginDrawing();
            ClearBackground(BLACK);
            
            //-------------- 3d portion
            BeginMode3D(camera);

                DrawGrid(50, 1.0f);
            
            EndMode3D();
            //-----------------
            //we can add 2d overlays here:
    
        EndDrawing();
    }

    
     CloseWindow();
    return 0;
}