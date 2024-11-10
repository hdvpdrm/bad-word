#include"BadWordRandomizer.h"

BadWordRandomizer::BadWordRandomizer()
{
  generate();
}
BadWordRandomizer::~BadWordRandomizer()
{
}
void BadWordRandomizer::generate()
{
  static const char* chars = "FUCKFUCK\0";
  for(short i = 0;i<8;++i)
    {
      seq.push_back(chars[i]);
    }
  Random::shuffle(seq.begin(),seq.end());
}
char BadWordRandomizer::get()
{
  if(seq.empty())generate();
  
  auto el = (--seq.end());
  seq.pop_back();
  return *el;
}
