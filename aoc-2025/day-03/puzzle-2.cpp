#include <algorithm>
#include <iostream>
#include <string>

int main() {
  long long totalJoltage{0};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::string digits{line.substr(line.size() - 12)};

    for (std::size_t i{line.size() - 12}; i > 0; --i) {
      char digit{line[i - 1]};
      for (std::size_t i{0}; i < digits.size(); ++i) {
        if (digit < digits[i]) break;
        std::swap(digit, digits[i]);
      }
    }

    long long joltage{0};
    for (const char digit : digits) joltage = joltage * 10 + digit - '0';

    totalJoltage += joltage;
  }

  std::cout << totalJoltage << "\n";

  return 0;
}
