#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

class Screen{
  private:
    std::vector<std::vector<char>> screen;
    int width, height;
    bool border;
  public:
    Screen(int width, int height);
    void show();
    void addBorder(std::string bor = "#=##|#");
};

#endif