#include <iostream>
#include <string>

struct Robot {
  int x;
  int y;
  int vx;
  int vy;

  void move() {
    x = (101 + x + vx) % 101;
    y = (103 + y + vy) % 103;
  }
};

int main() {
  std::vector<Robot> robots{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    int x{0};
    std::size_t i{2};
    while (line[i] != ',') {
      x = x * 10 + line[i] - '0';
      ++i;
    }

    int y{0};
    ++i;
    while (line[i] != ' ') {
      y = y * 10 + line[i] - '0';
      ++i;
    }

    int vx{0};
    i += 3;
    bool neg{false};
    if (line[i] == '-') {
      neg = true;
      ++i;
    }
    while (line[i] != ',') {
      vx = vx * 10 + line[i] - '0';
      ++i;
    }
    if (neg) vx = -vx;

    int vy{0};
    ++i;
    if (line[i] == '-') {
      neg = true;
      ++i;
    } else {
      neg = false;
    }
    while (line[i] != 0) {
      vy = vy * 10 + line[i] - '0';
      ++i;
    }
    if (neg) vy = -vy;

    robots.push_back({.x = x, .y = y, .vx = vx, .vy = vy});
  }

  int step{1};
  while (true) {
    std::vector<std::string> lines(103, std::string(101, '.'));
    for (auto& robot : robots) {
      robot.move();
      lines[robot.y][robot.x] = 'X';
    }

    for (std::size_t by{0}; by < lines.size() - 1; ++by) {
      for (std::size_t bx{0}; bx < lines[by].size() - 1; ++bx) {
        if (lines[by][bx] != 'X') continue;

        if (lines[by][bx + 1] != 'X') continue;
        if (lines[by + 1][bx] != 'X') continue;

        std::size_t ex{bx + 1};
        while (ex + 1 < lines[by].size() && lines[by][ex + 1] == 'X') ++ex;

        std::size_t ey{by + 1};
        while (ey + 1 < lines.size() && lines[ey + 1][bx] == 'X') ++ey;

        bool good{true};
        for (std::size_t x{bx}; x <= ex; ++x) {
          if (lines[ey][x] != 'X') {
            good = false;
            break;
          }
        }
        if (!good) continue;

        for (std::size_t y{by}; y <= ey; ++y) {
          if (lines[y][ex] != 'X') {
            good = false;
            break;
          }
        }
        if (!good) continue;

        std::size_t count{0};
        for (std::size_t y{by}; y <= ey; ++y) {
          for (std::size_t x{bx}; x <= ex; ++x) {
            if (lines[y][x] == 'X') ++count;
          }
        }

        if (count * 2 < robots.size()) continue;

        std::cout << step << "\n";
        return 0;
      }
    }

    ++step;
  }

  std::cout << step << "\n";
  return 0;
}
