#include <iostream>
#include <string>

int main() {
  int joltage{0};

  std::string line{};
  while (std::getline(std::cin, line)) {
    char a{line[line.size() - 2]};
    char b{line[line.size() - 1]};
    for (std::size_t i{line.size() - 2}; i > 0; --i) {
      if (line[i - 1] >= a) {
        if (a > b) b = a;
        a = line[i - 1];
      }
    }
    joltage += (a - '0') * 10 + b - '0';
  }

  std::cout << joltage << "\n";

  return 0;
}
