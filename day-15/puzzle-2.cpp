#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line) && !line.empty()) {
    lines.push_back(line);
  }

  std::size_t ry{0}, rx{0};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      if (lines[y][x] == '@') {
        lines[y][x] = '.';
        ry = y;
        rx = x;
        y = lines.size();
        x = lines[y].size();
      }
    }
  }

  while (std::getline(std::cin, line)) {
    for (const auto c : line) {
      std::size_t x{}, y{};
      switch (c) {
        case '^':
          y = ry - 1;
          while (lines[y][rx] == 'O') --y;
          if (lines[y][rx] == '.') {
            lines[y][rx] = 'O';
            lines[--ry][rx] = '.';
          }
          break;

        case 'v':
          y = ry + 1;
          while (lines[y][rx] == 'O') ++y;
          if (lines[y][rx] == '.') {
            lines[y][rx] = 'O';
            lines[++ry][rx] = '.';
          }
          break;

        case '<':
          x = rx - 1;
          while (lines[ry][x] == 'O') --x;
          if (lines[ry][x] == '.') {
            lines[ry][x] = 'O';
            lines[ry][--rx] = '.';
          }
          break;

        case '>':
          x = rx + 1;
          while (lines[ry][x] == 'O') ++x;
          if (lines[ry][x] == '.') {
            lines[ry][x] = 'O';
            lines[ry][++rx] = '.';
          }
          break;
      }
    }
  }

  std::size_t sum{0};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      if (lines[y][x] == 'O') sum += 100 * y + x;
    }
  }

  std::cout << sum << "\n";
  return 0;
}
