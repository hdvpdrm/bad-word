#include"GameScene.h"

GameScene::GameScene(int id, int next_id):BaseScene(id,next_id)
{
  font = LoadFontFromMemory(".ttf", ARCADECLASSIC_TTF, ARCADECLASSIC_TTF_len, 28, NULL, 0);
  
}
GameScene::~GameScene()
{
  UnloadFont(font);
}
void GameScene::run()
{
  if(!grid.is_able_to_play())return;

  auto dir = update();
  grid.move(dir);
  score += grid.get_score();
}
void GameScene::draw()
{
  draw_matrix();
  draw_words();
}
void GameScene::draw_words()
{
  for(int y = 0;y<5;++y)
    for(int x = 0;x<5;++x)
      {
	auto val = grid.get_element(iVector2(x,y));
	auto x_pos = (x*80)+125 - (val.size()*3.5);
	auto y_pos = (y*80)+80;

	DrawTextEx(font,val.c_str(),(Vector2){x_pos,y_pos},32,0,fuck_color);
      }
}
void GameScene::draw_matrix()
{
  DrawRectangle(100,50,5*80,5,fuck_color);
  DrawRectangle(100,50,5,5*80,fuck_color);
  DrawRectangle(100,450,(5*80)+5,5,fuck_color);
  DrawRectangle(500,50,5,5*80,fuck_color);

  for(short i = 0;i<5;++i)
    {
      DrawRectangle(100+(i*80),50,5,5*80,fuck_color);
      DrawRectangle(100,50+(i*80),5*80,5,fuck_color);
    }

  std::string text = "your  fucking  score  is  "+std::to_string(score);
  DrawTextEx(font,text.c_str(),(Vector2){10,10},28,0,fuck_color);
}
Grid::TransformDirection GameScene::update()
{
  if(IsKeyReleased(KEY_LEFT) ||
     IsKeyReleased(KEY_A))
    return Grid::TransformDirection::Left;
  else if (IsKeyReleased(KEY_RIGHT) ||
     IsKeyReleased(KEY_D))
    return Grid::TransformDirection::Right;
  else if (IsKeyReleased(KEY_UP) ||
     IsKeyReleased(KEY_W))
    return Grid::TransformDirection::Up;
  else if (IsKeyReleased(KEY_DOWN) ||
     IsKeyReleased(KEY_S))
    return Grid::TransformDirection::Down;
  else
    return Grid::TransformDirection::None;
}
bool GameScene::is_out(iVector2 pos,iVector2 movement_vec)
{
  auto vec = pos+movement_vec;

  bool check_x = vec.x == -1 || vec.x == 5;
  bool check_y = vec.y == -1 || vec.y == 5;
  return check_x || check_y;
}
