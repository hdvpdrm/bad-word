#ifndef VECTOR2_H
#define VECTOR2_H

//raylib's vector kinda sucks and I hate it
template<typename T>
struct MyVector2
{
  T x, y;
  MyVector2(T x, T y):x(x),y(y){}
  MyVector2(const MyVector2<T>& vec):x(vec.x),y(vec.y){}
  ~MyVector2(){}

  bool operator==(const MyVector2<T>& element){ return x == element.x && y == element.y;}

  friend MyVector2<T> operator-(const MyVector2<T>& a,const MyVector2<T>& b){ return MyVector2<T>(a.x-b.x,a.y-b.y);}
  friend MyVector2<T> operator+(const MyVector2<T>& a,const MyVector2<T>& b){ return MyVector2<T>(a.x+b.x,a.y+b.y);}
};
typedef MyVector2<int> iVector2;
typedef MyVector2<float> fVector2;
#endif
