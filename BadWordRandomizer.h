#ifndef BAD_WORD_RANDOMIZER_H
#define BAD_WORD_RANDOMIZER_H
#include"random.hpp"
#include<vector>

using Random = effolkronium::random_static;
class BadWordRandomizer
{
 private:
  std::vector<char> seq;
  void generate();
 public:
  BadWordRandomizer();
  ~BadWordRandomizer();

  char get();
};
#endif
