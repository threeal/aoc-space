#include <iostream>
#include <string>
#include <vector>

enum class Dir {
  Up,
  Right,
  Down,
  Left
};

enum {
  FLAG = 1,
  OBSTACLE = 2,
  CHECKED = 4,
  UP = 8,
  RIGHT = 16,
  DOWN = 32,
  LEFT = 64
};

// shoule be higher than 721
int main() {
  std::vector<std::string> lines{};
  std::size_t x{}, y{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    for (std::size_t i{0}; i < line.size(); ++i) {
      switch (line[i]) {
        case '#':
          line[i] = FLAG | OBSTACLE;
          break;

        case '^':
          x = i;
          y = lines.size();

        default:
          line[i] = FLAG;
      }
    }
    lines.push_back(line);
  }

  int count{0};

  Dir dir{Dir::Up};
  while (true) {
    switch (dir) {
      case Dir::Up:
        lines[y][x] |= UP;
        if (y == 0) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y - 1][x] == (FLAG | OBSTACLE)) {
          dir = Dir::Right;
        } else {
          if ((lines[y - 1][x] & CHECKED) == 0) {
            for (std::size_t i{x}; i < lines[y].size(); ++i) {
              if ((lines[y][i] & RIGHT) != 0) {
                std::cout << "UP " << x << " " << y - 1 << " " << i << "\n";
                ++count;
                lines[y - 1][x] |= CHECKED;
                break;
              }
            }
          }
          --y;
        }
        break;

      case Dir::Right:
        lines[y][x] |= RIGHT;
        if (x == lines[y].size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y][x + 1] == (FLAG | OBSTACLE)) {
          dir = Dir::Down;
        } else {
          if ((lines[y][x + 1] & CHECKED) == 0) {
            for (std::size_t i{y}; i < lines.size(); ++i) {
              if ((lines[i][x] & DOWN) != 0) {
                std::cout << "RIGHT " << x + 1 << " " << y << "\n";
                ++count;
                lines[y][x + 1] |= CHECKED;
                break;
              }
            }
          }
          ++x;
        }
        break;

      case Dir::Down:
        lines[y][x] |= DOWN;
        if (y == lines.size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y + 1][x] == (FLAG | OBSTACLE)) {
          dir = Dir::Left;
        } else {
          if ((lines[y + 1][x] & CHECKED) == 0) {
            for (std::size_t i{x}; i > 0; --i) {
              if ((lines[y][i] & LEFT) != 0) {
                std::cout << "DOWN " << x << " " << y + 1 << "\n";
                ++count;
                lines[y + 1][x] |= CHECKED;
                break;
              }
            }
          }
          ++y;
        }
        break;

      case Dir::Left:
        lines[y][x] |= LEFT;
        if (x == 0) {
          std::cout << count << "\n";
          return 0;
        } else if (lines[y][x - 1] == (FLAG | OBSTACLE)) {
          dir = Dir::Up;
        } else {
          if ((lines[y][x - 1] & CHECKED) == 0) {
            for (std::size_t i{y}; i > 0; --i) {
              if ((lines[i][x] & UP) != 0) {
                std::cout << "LEFT " << x - 1 << " " << y << "\n";
                ++count;
                lines[y][x - 1] |= CHECKED;
                break;
              }
            }
          }
          --x;
        }
        break;
    }
  }
}
