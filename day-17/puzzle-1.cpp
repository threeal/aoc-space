#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  if (!std::getline(std::cin, line)) return 1;

  int a{0};
  for (std::size_t i{12}; i < line.size(); ++i) {
    a = a * 10 + line[i] - '0';
  }

  if (!std::getline(std::cin, line)) return 1;

  int b{0};
  for (std::size_t i{12}; i < line.size(); ++i) {
    b = b * 10 + line[i] - '0';
  }

  if (!std::getline(std::cin, line)) return 1;

  int c{0};
  for (std::size_t i{12}; i < line.size(); ++i) {
    c = c * 10 + line[i] - '0';
  }

  while (std::getline(std::cin, line) && line.empty());

  std::vector<int> program{};
  for (std::size_t i{9}; i < line.size(); i += 2) {
    program.push_back(line[i] - '0');
  }

  std::cout << a << " " << b << " " << c << "\n";
  for (const auto reg : program) std::cout << reg << " ";
  std::cout << "\n";

  return 0;
}
