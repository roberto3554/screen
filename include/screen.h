#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include "controller.h"

class Screen{
  private:
    std::vector<std::vector<char>> screen;
    int width, height;
    bool border;
  public:
    Controller controller;
    Screen(int width, int height);
    void show();
    void addBorder(std::string bor = "#=##|#");
    void addChar(int x, int y, char c);
};

#endif