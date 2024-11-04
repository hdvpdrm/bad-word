#ifndef START_MENU_H
#define START_MENU_H
#include"BaseScene.h"
#include"font.h"
#include"Timer.h"
#include<string>
#include<functional>
#include<raylib.h>
#include<stdio.h>

#define CHECK_KEY_LAMBDA(x) [](){return IsKeyReleased(x);}
class StartMenu: public GG::BaseScene
{
 private:
  Font label_font, button_font;
  Color label_color = {5,0,12,255};
  Color fuck_color = {183,178,190,255};
  bool fuck_pressed_checkers[4] = {true,false,false,false};
  const std::function<bool()> key_predicats[4] = {
    CHECK_KEY_LAMBDA(KEY_F),
    CHECK_KEY_LAMBDA(KEY_U),
    CHECK_KEY_LAMBDA(KEY_C),
    CHECK_KEY_LAMBDA(KEY_K)
  };
  short lambda_to_choose = 0;
  void check_keys();
  
  std::string get_fuck_to_draw();
  
 public:
  StartMenu(int id, int next_id);
  ~StartMenu();

  void run();
  void draw();

};
#endif
