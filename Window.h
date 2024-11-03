#ifndef WINDOW_H
#define WINDOW_H
#include"BaseScene.h"
#include<raylib.h>
#include<unordered_map>
#include<functional>

namespace GG
{
class Window
{
 private:
  BaseScene* current_scene = nullptr;
  std::unordered_map<int,std::function<BaseScene*()>> scenes;

  Color background = BLACK; //default value
 public:
  Window(const char* title);
  ~Window();
  void run();
  
  bool add(int id,std::function<BaseScene*()> creator);
  bool set_initial_scene(int id);

  void set_background_color(Color color){background = color;};
 private:
  void draw();
  bool does_id_exists(int id);
};
};


#endif //WINDOW_H
