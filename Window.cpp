#include"Window.h"

GG::Window::Window(const char* title)
{
  InitWindow(640,480,title);
  InitAudioDevice();
  ClearWindowState(FLAG_WINDOW_RESIZABLE);	// window isn't resizable
  SetTargetFPS(60);
}
GG::Window::~Window()
{
  CloseAudioDevice();
  CloseWindow();
}

void GG::Window::run()
{
  while(!WindowShouldClose())
    {
       if(current_scene != nullptr)
	 current_scene->run();

       if(current_scene->should_change())
	 {
	   auto next_id = current_scene->get_next_id();
	   auto ret_val = current_scene->get_return_value();
	   delete current_scene;
	   current_scene = scenes[next_id]();
	   current_scene->set_return_value(ret_val);
	 }
       
      draw();
    }
}
void GG::Window::draw()
{
  BeginDrawing();
  
  if(current_scene != nullptr)
	 current_scene->draw();
  
  ClearBackground(background);
  EndDrawing();
}

bool GG::Window::does_id_exists(int id)
{
  return scenes.find(id) != scenes.end();
}
bool GG::Window::add(int id, std::function<BaseScene*()> creator)
{
  if(does_id_exists(id)) return false;

  scenes[id] = creator;
  return true;
}
bool GG::Window::set_initial_scene(int id)
{
  if(!does_id_exists(id)) return false;

  current_scene = scenes[id]();
  return true;
}
