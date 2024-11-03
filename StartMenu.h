#ifndef START_MENU_H
#define START_MENU_H
#include"BaseScene.h"
#include"font.h"
#include<raylib.h>
#include<stdio.h>

class StartMenu: public GG::BaseScene
{
 private:
  Font label_font, button_font;
  Color label_color = {5,0,12,255};
 public:
  StartMenu(int id, int next_id);
  ~StartMenu();

  void run();
  void draw();

};
#endif
