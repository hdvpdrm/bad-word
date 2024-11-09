#ifndef BAD_WORD_H
#define BAD_WORD_H
#include"Vector2.h"
#include<string>
#include<raylib.h>

struct BadWord
{
  std::string content;
  iVector2 pos;
  
  BadWord(std::string content,iVector2 pos):content(content),pos(pos){}
  ~BadWord(){}
};



#endif
