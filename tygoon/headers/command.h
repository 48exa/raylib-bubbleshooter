#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <iostream>

class Command {
public:
  Command(std::function<void()> function, std::string desc);
  ~Command();

  void execute();
  std::string Description() { return description; };

private:
  // NOTE - callback func set with lambda
  std::function<void()> cmd_function;
  std::string description;
};

#endif