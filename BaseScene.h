#ifndef BASE_SCENE_H
#define BASE_SCENE_H
#include<unordered_map>
#include<string>

namespace GG
{
class BaseScene
{
protected:
  bool should_quit = false;
  std::unordered_map<std::string, std::string> return_value;
private:
  int id, next_id;
public:
  BaseScene(int id,
	    int next_id):
    id(id),
    next_id(next_id)
  {}
  ~BaseScene(){}
  
  int get_id()const {return id;}
  int get_next_id()const {return next_id;}

  virtual void run()=0;
  virtual void draw()=0;

  bool should_change() {return should_quit;}

  std::unordered_map<std::string,std::string> get_return_value(){ return return_value;}
  void set_return_value(std::unordered_map<std::string,std::string>& ret_val)
  {
    for(auto& el:ret_val)
      {
	return_value[el.first] = el.second;
      }
  }
};
};
#endif
