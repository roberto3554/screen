#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <functional>

class Controller{
  private:
    std::map<char, std::function<void()>> actions;
  public:
    Controller();
    void registerAction(const char key, std::function<void()> function);
    void waitForAction(const char key);
};

#endif