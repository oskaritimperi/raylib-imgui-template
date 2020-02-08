#include "raylib.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_raylib.h"

int main(int argc, char* argv[])
{
    int screenWidth = 1024;
    int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "{{cookiecutter.project_name}}");

    SetTargetFPS(60);

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplOpenGL3_Init();
    ImGui_ImplRaylib_Init();

    while (!WindowShouldClose())
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplRaylib_NewFrame();
        ImGui::NewFrame();
        ImGui_ImplRaylib_ProcessEvent();

        BeginDrawing();

        {
            ClearBackground(RAYWHITE);

            ImGui::ShowDemoWindow();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        EndDrawing();
    }

    ImGui_ImplRaylib_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();

    CloseWindow();

    return 0;
}
