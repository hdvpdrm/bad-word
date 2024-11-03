#include"StartMenu.h"


StartMenu::StartMenu(int id, int next_id):GG::BaseScene(id,next_id)
{
  label_font = LoadFontFromMemory(".ttf", fibberish_ttf, fibberish_ttf_len, 48, NULL, 0);
  button_font = LoadFontFromMemory(".ttf", fibberish_ttf, fibberish_ttf_len, 32, NULL, 0);

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
}
void StartMenu::draw()
{
  DrawTextEx(label_font,"Bad Word",(Vector2){200,100},48,0,label_color);
}

