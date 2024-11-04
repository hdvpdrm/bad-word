#ifndef BASE_SCENE_H
#define BASE_SCENE_H

namespace GG
{
class BaseScene
{
protected:
   bool should_quit = false;
private:
  int id, next_id;
public:
  BaseScene(int id, int next_id):id(id),next_id(next_id)
  {}
  ~BaseScene(){}
  
  int get_id()const {return id;}
  int get_next_id()const {return next_id;}

  virtual void run()=0;
  virtual void draw()=0;

  bool should_change() {return should_quit;}
};
};
#endif
