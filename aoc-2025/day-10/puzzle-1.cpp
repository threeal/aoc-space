#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

static int findCombination(
    std::uint32_t indicators, const std::vector<std::uint32_t>& buttons,
    std::size_t i, std::uint32_t current) {
  if (indicators == current) return 0;
  if (i >= buttons.size()) return buttons.size();
  return std::min(
      findCombination(indicators, buttons, i + 1, current),
      1 + findCombination(indicators, buttons, i + 1, current ^ buttons[i]));
}

int main() {
  int sum{0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    std::uint32_t indicators{0};

    std::size_t i{1};
    while (line[i] != ']') {
      if (line[i] == '#') indicators |= 1 << (i - 1);
      ++i;
    }

    std::vector<uint32_t> buttons{};

    i += 2;
    while (line[i] != '{') {
      std::uint32_t button{0}, num{0};

      ++i;
      while (line[i] != ')') {
        if (line[i] == ',') {
          button |= 1 << num;
          num = 0;
        } else {
          num = num * 10 + line[i] - '0';
        }
        ++i;
      }

      buttons.push_back(button | 1 << num);
      i += 2;
    }

    sum += findCombination(indicators, buttons, 0, 0);
  }

  std::cout << sum << "\n";

  return 0;
}
