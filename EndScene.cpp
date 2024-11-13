#include"EndScene.h"


EndScene::EndScene(int id, int next_id):BaseScene(id, next_id)
{
  font = LoadFontFromMemory(".ttf", ARCADECLASSIC_TTF, ARCADECLASSIC_TTF_len, 28, NULL, 0);
}
EndScene::~EndScene()
{
  UnloadFont(font);
}

void EndScene::run()
{
  if(GetKeyPressed() != 0)
    {
      should_quit = true;
    }
}
void EndScene::draw()
{
  std::string val = "you  fucking  score  was  "+return_value["score"];
  DrawTextEx(font,val.c_str(),(Vector2){140,200},32,0,fuck_color);
}
