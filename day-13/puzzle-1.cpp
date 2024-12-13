#include <iostream>
#include <string>

int main() {
  int tokens{0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{12};
    int ax{0};
    while (line[i] != ',') {
      ax = ax * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    int ay{0};
    while (i < line.size()) {
      ay = ay * 10 + line[i] - '0';
      ++i;
    }

    if (!std::getline(std::cin, line)) break;
    i = 12;
    int bx{0};
    while (line[i] != ',') {
      bx = bx * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    int by{0};
    while (i < line.size()) {
      by = by * 10 + line[i] - '0';
      ++i;
    }

    if (!std::getline(std::cin, line)) break;
    i = 9;
    int px{0};
    while (line[i] != ',') {
      px = px * 10 + line[i] - '0';
      ++i;
    }
    i += 4;
    int py{0};
    while (i < line.size()) {
      py = py * 10 + line[i] - '0';
      ++i;
    }

    for (int b{std::min(100, px / bx)}; b >= 0; --b) {
      const int dx{px - b * bx};
      const int dy{py - b * by};
      if (dx % ax == 0 && dy % ay == 0 && dx / ax == dy / ay) {
        if (dx / ax <= 100) {
          tokens += b + 3 * dx / ax;
          break;
        }
      }
    }

    if (!std::getline(std::cin, line)) break;
  }

  std::cout << tokens << "\n";
  return 0;
}
