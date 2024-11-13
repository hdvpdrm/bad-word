#include"Grid.h"

Grid::Grid()
{
    for(short y = 0;y<5;++y)
      {
	std::vector<std::string> line;
	for(short x = 0;x<5;++x)
	  {
	    line.push_back("");
	  }
	grid.push_back(line);
      }
	  	   
    create_random_bad_word();
    create_random_bad_word();

    fuck_complete_wav = LoadWaveFromMemory(".wav",fuck_sound_wav,fuck_sound_wav_len);
    fuck_complete_sound = LoadSoundFromWave(fuck_complete_wav);
}
Grid::~Grid()
{
  UnloadWave(fuck_complete_wav);
  UnloadSound(fuck_complete_sound);
}
std::string& Grid::get_element(const iVector2& pos)
{
  return grid[pos.y][pos.x];
}
std::vector<iVector2> Grid::get_free_spaces()
{
  std::vector<iVector2> free_spaces;
  for(short y = 0;y<5;++y)
    for(short x =0;x<5;++x)
      if(grid[y][x] == "")free_spaces.push_back(iVector2(x,y));

  return free_spaces;
}
void Grid::create_random_bad_word()
{
  auto positions = get_free_spaces();
  if(positions.empty())
    {
      can_play = false;
      return;
    }
  
  int id = Random::get(0,(int)positions.size()-1);

  auto rand_pos = positions[id];
  std::string str;
  str+=word_randomizer.get();
  grid[rand_pos.y][rand_pos.x] = str;
}
bool Grid::can_be_united(const std::string& a, const std::string& b)
{
  auto s = a+b;
  bool check1 = s == "FU";
  bool check2 = s == "FUC";
  bool check3 = s == "FUCK";
  return check1 || check2 || check3;
}

void Grid::move_all_left()
{
  for(int y = 0;y<5;++y)
    {
      grid[y] = move_line_left(grid[y]);
      merge_adjacent_equal_elements(grid[y]);
      grid[y] = move_line_left(grid[y]);
    }
}
std::vector<std::string> Grid::move_line_left(std::vector<std::string>& line)
{
  std::vector<std::string> new_line= {"","","","",""};
  short i_to_set = 0;
  for(short i = 0;i<5;++i)
    {
      if(line[i] != "")
	{
	  new_line[i_to_set] = line[i];
	  ++i_to_set;
	}
    }
  return new_line;
}

void Grid::move_all_right()
{
  for(int y = 0;y<5;++y)
    {
      grid[y] = move_line_right(grid[y]);
      merge_adjacent_equal_elements_reversed(grid[y]);
      grid[y] = move_line_right(grid[y]);
    }
}
std::vector<std::string> Grid::move_line_right(std::vector<std::string>& line)
{
  std::vector<std::string> new_line= {"","","","",""};
  short i_to_set = 4;
  for(short i = 4;i>-1;--i)
    {
      if(line[i] != "")
	{
	  new_line[i_to_set] = line[i];
	  --i_to_set;
	}
    }
  return new_line;
}

std::vector<std::string> Grid::get_line_along_y(short x)
{
  std::vector<std::string> line;

  for(int y = 0;y<5;++y)
    line.push_back(grid[y][x]);

  return line;
}
void Grid::set_line_along_y(short x, std::vector<std::string>& line)
{
  for(int y = 0;y<5;++y)
    {
      grid[y][x] = line[y];
    }
}
void Grid::move_all_down()
{
  for(int x = 0;x<5;++x)
    {
      auto line = get_line_along_y(x);
      line = move_line_right(line);
      merge_adjacent_equal_elements_reversed(line);
      line = move_line_right(line);
      set_line_along_y(x,line);
    }
}
void Grid::move_all_up()
{
  for(int x = 0;x<5;++x)
    {
      auto line = get_line_along_y(x);
      line = move_line_left(line);
      merge_adjacent_equal_elements(line);
      line = move_line_left(line);
      set_line_along_y(x,line);
    }
}

void Grid::move(TransformDirection dir)
{
  if(dir == TransformDirection::Left)
    move_all_left();
  if(dir == TransformDirection::Right)
    move_all_right();
  if(dir == TransformDirection::Down)
    move_all_down();
  if(dir == TransformDirection::Up)
    move_all_up();

  if(dir != TransformDirection::None)
      create_random_bad_word();
}
void Grid::merge_adjacent_equal_elements(std::vector<std::string>& line)
{
  for(short i = 0;i<4;++i)
    {
      auto a = line[i];
      auto b = line[i+1];
      if(can_be_united(a,b))
	{
	  line[i] = a+b;
	  line[i+1].clear();
	}
      if(can_be_united(b,a))
	{
	  line[i] = b+a;
	  line[i+1].clear();
	}
    }
}
void Grid::merge_adjacent_equal_elements_reversed(std::vector<std::string>& line)
{
  for(short i = 4;i>0;--i)
    {
      auto a = line[i];
      auto b = line[i-1];
      if(can_be_united(a,b))
	{
	  line[i-1] = a+b;
	  line[i].clear();
	}
      if(can_be_united(b,a))
	{
	  line[i-1] = b+a;
	  line[i].clear();
	}
    }
}
int Grid::get_score()
{
  int score = 0;
  for(int y = 0;y<5;++y)
    for(int x = 0;x<5;++x)
      if(grid[y][x] == "FUCK")
	{
	  grid[y][x].clear();
	  ++score;
	  PlaySound(fuck_complete_sound);
	}

  return score;
}
