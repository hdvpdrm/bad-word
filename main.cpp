#include"Window.h"
#include"StartMenu.h"
int main()
{
  GG::Window window("Bad Word");

  Color background = {54,3,116,255};
  window.set_background_color(background);
  
  if(window.add(0,[](){return new StartMenu(0,1);}))
    {
      printf("%s\n","Starting menu is added successfully.");
    }
  if(window.set_initial_scene(0))
    {
      printf("%s\n","initial scene is set up successfully!");
    }
  else
    {
      printf("%s\n","initial scene is fucked up!");
      return -1;
    }
  window.run();

  return 0;
}
