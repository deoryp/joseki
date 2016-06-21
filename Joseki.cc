#include <iostream>
#include <string>

void print(int indent, std::string line) {
  std::cout << std::string(indent, ' ') << line << std::endl;
}

int main() {

  std::string node;
  std::string line;
  std::string sgf;
  std::cout << "SGF: \n";

  int spacing = 0;

  while(std::getline(std::cin, line)) {
    sgf += line;
    for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
      switch (*it){
        case '(':
          spacing += 1;
          print(spacing, "Start variation.");
          spacing += 1;
          break;
        case ')':
          spacing -= 1;
          print(spacing, "End variation.");
          spacing -= 1;
          break;
        case ';':
          print(spacing, "Node.");
          break;
      }
    }
  }

  std::cout << sgf << std::endl;

  return 0;
}
