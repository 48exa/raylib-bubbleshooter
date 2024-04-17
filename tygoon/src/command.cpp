#include <command.h>

Command::Command(std::function<void()> function, std::string desc) {
  this->cmd_function = function;
  this->description = desc;
}

Command::~Command() {
  // Nothing to do here
}

void Command::execute() {
  std::cout << "##### Executing command #####" << std::endl;
  this->cmd_function();
}
