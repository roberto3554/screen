#include "screen.h"
#include <iostream>

// g++ main.cpp screen.cpp -o main.exe

int main(){
  Screen s(16, 8);
  s.addBorder();
  s.show();

  return 0;
}