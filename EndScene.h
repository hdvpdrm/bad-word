#ifndef END_SCENE_H
#define END_SCENE_H
#include"BaseScene.h"
#include"game_font.h"
#include<string>
#include<raylib.h>

class EndScene: public GG::BaseScene
{
 private:
  Font font;
  Color fuck_color = {183,178,190,255};
 public:
  EndScene(int id, int next_id);
  ~EndScene();

  void run();
  void draw();
};
#endif
