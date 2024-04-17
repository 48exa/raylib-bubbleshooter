#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <iostream>

class Command {
public:
  Command(std::function<void()> function);
  ~Command();

  void execute();

private:
  std::function<void()> cmd_function;
};

#endif