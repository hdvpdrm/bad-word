#include"Window.h"

GG::Window::Window(const char* title)
{
  InitWindow(640,480,title);
  ClearWindowState(FLAG_WINDOW_RESIZABLE);	// window isn't resizable
  SetTargetFPS(60);
}
GG::Window::~Window()
{
  CloseWindow();
}

void GG::Window::run()
{
  while(!WindowShouldClose())
    {
      draw();
    }
}
void GG::Window::draw()
{
  BeginDrawing();
  ClearBackground(BLACK);
  EndDrawing();
}

