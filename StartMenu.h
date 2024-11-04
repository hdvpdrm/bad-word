#ifndef START_MENU_H
#define START_MENU_H
#include"BaseScene.h"
#include"font.h"
#include"Timer.h"
#include"sounds/sound1.h"
#include"sounds/sound2.h"
#include"sounds/sound3.h"
#include"sounds/sound4.h"
#include<string>
#include<functional>
#include<raylib.h>
#include<stdio.h>

#define CHECK_KEY_LAMBDA(x) [](){return IsKeyReleased(x);}
class StartMenu: public GG::BaseScene
{
 private:
  Font button_font;
  Color fuck_color = {183,178,190,255};
  bool fuck_pressed_checkers[4] = {true,false,false,false};
  const std::function<bool()> key_predicats[4] = {
    CHECK_KEY_LAMBDA(KEY_F),
    CHECK_KEY_LAMBDA(KEY_U),
    CHECK_KEY_LAMBDA(KEY_C),
    CHECK_KEY_LAMBDA(KEY_K)
  };
  short lambda_to_choose = 0;

  Wave fuck_waves[4];
  Sound fuck_sounds[4];
  
  void check_keys();
  
  std::string get_fuck_to_draw();
  
 public:
  StartMenu(int id, int next_id);
  ~StartMenu();

  void run();
  void draw();

};
#endif
