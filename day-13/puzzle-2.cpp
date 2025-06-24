#include <iostream>
#include <string>

int main() {
  long long tokens{0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{12};
    long long ax{0};
    while (line[i] != ',') {
      ax = ax * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    long long ay{0};
    while (i < line.size()) {
      ay = ay * 10 + line[i] - '0';
      ++i;
    }

    if (!std::getline(std::cin, line)) break;
    i = 12;
    long long bx{0};
    while (line[i] != ',') {
      bx = bx * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    long long by{0};
    while (i < line.size()) {
      by = by * 10 + line[i] - '0';
      ++i;
    }

    if (!std::getline(std::cin, line)) break;
    i = 9;
    long long px{};
    while (line[i] != ',') {
      px = px * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    long long py{0};
    while (i < line.size()) {
      py = py * 10 + line[i] - '0';
      ++i;
    }

    px += 10000000000000;
    py += 10000000000000;

    const long long det{ax * by - bx * ay};
    if (det != 0) {
      const long long a{px * by - bx * py};
      if (a % det == 0) {
        const long long b{ax * py - px * ay};
        if (b % det == 0) {
          tokens += 3 * a / det + b / det;
        }
      }
    }

    if (!std::getline(std::cin, line)) break;
  }

  std::cout << tokens << "\n";
  return 0;
}
