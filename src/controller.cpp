#include "../include/controller.h"

Controller::Controller(){

}

void Controller::registerAction(const char key, std::function<void()> function){
  actions[key] = function;
}

void Controller::waitForAction(const char key){
  auto it = actions.find(key);
   if (it != actions.end()) {
    it->second();
  }
}