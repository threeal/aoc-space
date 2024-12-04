#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }
  return 0;
}
