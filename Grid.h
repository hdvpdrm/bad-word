#ifndef GRID_H
#define GRID_H
#include<string>
#include<vector>
#include<algorithm>
#include"Vector2.h"
#include"BadWordRandomizer.h"

class Grid
{
 private:
  std::vector<std::vector<std::string>> grid;
  BadWordRandomizer word_randomizer;

  bool can_play = true;
 public:
  Grid();
  ~Grid();

  std::string& get_element(const iVector2& pos);
  
  enum class TransformDirection
    {
      Left,Right,Up,Down,None
    };

  void move(TransformDirection dir);
  int get_score();
  bool is_able_to_play(){ return can_play;}
 private:
  std::vector<iVector2> get_free_spaces();
  bool can_be_united(const std::string& a, const std::string& b);

  void move_all_left();
  std::vector<std::string> move_line_left(std::vector<std::string>& line);

  void move_all_right();
  std::vector<std::string> move_line_right(std::vector<std::string>& line);

  std::vector<std::string> get_line_along_y(short x);
  void set_line_along_y(short x, std::vector<std::string>& line);
  
  void move_all_down();
  void move_all_up();
  
  void merge_adjacent_equal_elements(std::vector<std::string>& line);
  void merge_adjacent_equal_elements_reversed(std::vector<std::string>& line);
  
  void create_random_bad_word();
};
#endif
