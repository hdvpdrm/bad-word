#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include"BaseScene.h"
#include"game_font.h"
#include"random.hpp"
#include"Vector2.h"
#include"Grid.h"
#include<stdio.h>
#include<raylib.h>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<limits.h>

using Random = effolkronium::random_static;
class GameScene: public GG::BaseScene
{
 private:  
  int score = 0;
  Grid grid;
  
  Font font;
  Color fuck_color = {183,178,190,255};
 public:
  GameScene(int id, int next_id);
  ~GameScene();

  void run();
  void draw();
 private:
  void draw_matrix();
  void draw_words();
  
  Grid::TransformDirection update();
  bool is_out(iVector2 pos, iVector2 movement_vec);
 
};
#endif
