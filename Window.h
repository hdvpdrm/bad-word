#ifndef WINDOW_H
#define WINDOW_H
#include<raylib.h>

namespace GG
{
class Window
{
 public:
  Window(const char* title);
  ~Window();
  void run();
  
 private:
  void draw();
};
};


#endif //WINDOW_H
