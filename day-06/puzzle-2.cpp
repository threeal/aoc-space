#include <iostream>
#include <string>
#include <vector>

enum class Dir {
  Up,
  Right,
  Down,
  Left
};

int main() {
  std::vector<std::string> lines{};
  std::size_t x{}, y{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    const std::size_t pos = line.find('^');
    if (pos != std::string::npos) {
      line[pos] = 'X';
      x = pos;
      y = lines.size();
    }
    lines.push_back(line);
  }

  int count{1};

  Dir dir{Dir::Up};
  while (true) {
    switch (dir) {
      case Dir::Up:
        if (y == 0) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y - 1][x] == '#') {
          dir = Dir::Right;
        } else {
          if (lines[y - 1][x] == '.') {
            lines[y - 1][x] = 'X';
            ++count;
          }
          --y;
        }
        break;

      case Dir::Right:
        if (x == lines[y].size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y][x + 1] == '#') {
          dir = Dir::Down;
        } else {
          if (lines[y][x + 1] == '.') {
            lines[y][x + 1] = 'X';
            ++count;
          }
          ++x;
        }
        break;

      case Dir::Down:
        if (y == lines.size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y + 1][x] == '#') {
          dir = Dir::Left;
        } else {
          if (lines[y + 1][x] == '.') {
            lines[y + 1][x] = 'X';
            ++count;
          }
          ++y;
        }
        break;

      case Dir::Left:
        if (x == 0) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y][x - 1] == '#') {
          dir = Dir::Up;
        } else {
          if (lines[y][x - 1] == '.') {
            lines[y][x - 1] = 'X';
            ++count;
          }
          --x;
        }
        break;
    }
  }
}
