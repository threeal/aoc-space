#include <iostream>
#include <string>

int main() {
  std::string line{};
  while (std::getline(std::cin, line)) {
    int secret{std::stoi(line)};
    std::cout << secret << "\n";
  }
  return 1;
}
