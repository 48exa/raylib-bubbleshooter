#include <command.h>

Command::Command(std::function<void()> function) {
  this->cmd_function = function;
}

Command::~Command() {
  // Nothing to do here
}

void Command::execute() {
  std::cout << "Executing command" << std::endl;
  this->cmd_function();
}
