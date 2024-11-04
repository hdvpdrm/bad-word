#include"StartMenu.h"


StartMenu::StartMenu(int id, int next_id):GG::BaseScene(id,next_id)
{
  button_font = LoadFontFromMemory(".ttf", fibberish_ttf, fibberish_ttf_len, 50, NULL, 0);

  if(!IsFontReady(button_font))
    {
      printf("%s\n","failed to load font!");
    }

  
  fuck_waves[0] = LoadWaveFromMemory(".wav",__1_wav,__1_wav_len);
  fuck_sounds[0] = LoadSoundFromWave(fuck_waves[0]);
    
  fuck_waves[1] = LoadWaveFromMemory(".wav",__2_wav,__2_wav_len);
  fuck_sounds[1] = LoadSoundFromWave(fuck_waves[1]);
  
  fuck_waves[2] = LoadWaveFromMemory(".wav",__4_wav,__4_wav_len);
  fuck_sounds[2] = LoadSoundFromWave(fuck_waves[2]);
  
  fuck_waves[3] = LoadWaveFromMemory(".wav",__3_wav,__3_wav_len);
  fuck_sounds[3] = LoadSoundFromWave(fuck_waves[3]);

  
  printf("%s\n","created starting menu!");
}
StartMenu::~StartMenu()
{
  UnloadFont(button_font);

  for(size_t i = 0;i<4;++i)
    {
      UnloadWave(fuck_waves[i]);
      UnloadSound(fuck_sounds[i]);
    }
}

void StartMenu::run()
{
  if(lambda_to_choose != 4)
    {
      check_keys();
    }
  else
    {
      should_quit = true;
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
  if(lambda_to_choose != 4)
    DrawTextEx(button_font,get_fuck_to_draw().c_str(),(Vector2){245,200},50,0,fuck_color);
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
      PlaySound(fuck_sounds[lambda_to_choose]);
      ++lambda_to_choose;
      if(lambda_to_choose != 4)
	fuck_pressed_checkers[lambda_to_choose] = true;
    }
}
