#include"StartMenu.h"


StartMenu::StartMenu(int id, int next_id):GG::BaseScene(id,next_id)
{
  label_font = LoadFontFromMemory(".ttf", fibberish_ttf, fibberish_ttf_len, 48, NULL, 0);
  button_font = LoadFontFromMemory(".ttf", fibberish_ttf, fibberish_ttf_len, 50, NULL, 0);

  if(!IsFontReady(label_font) && !IsFontReady(button_font))
    {
      printf("%s\n","failed to load font!");
    }

  printf("%s\n","created starting menu!");
}
StartMenu::~StartMenu()
{
  UnloadFont(label_font);
  UnloadFont(button_font);
}

void StartMenu::run()
{
  if(lambda_to_choose != 4)
    {
      check_keys();
    }
  else
    {
      if(IsKeyReleased(KEY_SPACE))
	{
	  should_quit = true;
	}
    }

  
  for(short i = 0;i<20;++i)
    {
      fuck_color.r-=1;
      fuck_color.g-=1;
      fuck_color.b-=1;
    }
}
void StartMenu::draw()
{
  DrawTextEx(label_font,"Bad Word",(Vector2){200,100},48,0,label_color);

  if(lambda_to_choose != 4)
    DrawTextEx(button_font,get_fuck_to_draw().c_str(),(Vector2){245,240},50,0,fuck_color);
  else
    {
      DrawTextEx(button_font,"press",(Vector2){100,240},50,0,label_color);
      DrawTextEx(button_font,"SPACE",(Vector2){230,240},50,0,fuck_color);
      DrawTextEx(button_font,"to play!",(Vector2){370,240},50,0,label_color);
    }
}
std::string StartMenu::get_fuck_to_draw()
{
  static const std::string FUCK = "FUCK";
  std::string out;
  for(size_t i = 0;i<4;++i)
    {
      if(fuck_pressed_checkers[i])out.push_back(FUCK[i]);
    }

  return out;
}
void StartMenu::check_keys()
{
  if(key_predicats[lambda_to_choose]())
    {
      ++lambda_to_choose;
      if(lambda_to_choose != 4)
	fuck_pressed_checkers[lambda_to_choose] = true;
    }

}
