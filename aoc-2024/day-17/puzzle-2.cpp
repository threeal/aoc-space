#include <iostream>
#include <string>
#include <vector>

int a{0}, b{0}, c{0};
int get_combo(int operand) {
  switch (operand) {
    case 0:
    case 1:
    case 2:
    case 3:
      return operand;

    case 4:
      return a;

    case 5:
      return b;

    case 6:
      return c;
  }

  return {};
}

int main() {
  std::string line{};
  if (!std::getline(std::cin, line)) return 1;
  for (std::size_t i{12}; i < line.size(); ++i) {
    a = a * 10 + line[i] - '0';
  }

  if (!std::getline(std::cin, line)) return 1;
  for (std::size_t i{12}; i < line.size(); ++i) {
    b = b * 10 + line[i] - '0';
  }

  if (!std::getline(std::cin, line)) return 1;
  for (std::size_t i{12}; i < line.size(); ++i) {
    c = c * 10 + line[i] - '0';
  }

  while (std::getline(std::cin, line) && line.empty());
  std::vector<int> program{};
  for (std::size_t i{9}; i < line.size(); i += 2) {
    program.push_back(line[i] - '0');
  }

  std::size_t i{0};
  bool first{true};
  while (i < program.size()) {
    switch (program[i]) {
      case 0:
        a = a / (1 << get_combo(program[i + 1]));
        i += 2;
        break;

      case 1:
        b = b ^ program[i + 1];
        i += 2;
        break;

      case 2:
        b = get_combo(program[i + 1]) % 8;
        i += 2;
        break;

      case 3:
        i = a == 0 ? i += 2 : program[i + 1];
        break;

      case 4:
        b = b ^ c;
        i += 2;
        break;

      case 5:
        if (!first) {
          std::cout << ",";
        } else {
          first = false;
        }
        std::cout << get_combo(program[i + 1]) % 8;
        i += 2;
        break;

      case 6:
        b = a / (1 << get_combo(program[i + 1]));
        i += 2;
        break;

      case 7:
        c = a / (1 << get_combo(program[i + 1]));
        i += 2;
        break;

      default:
        return 1;
    }
  }
  std::cout << "\n";
  return 0;
}
