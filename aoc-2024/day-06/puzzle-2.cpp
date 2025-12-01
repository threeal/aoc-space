#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

enum {
  FLAG = 1,
  OBSTACLE = 2,
  CHECKED = 4,
  UP = 8,
  RIGHT = 16,
  DOWN = 32,
  LEFT = 64
};

int main() {
  std::vector<std::string> lines{};
  std::size_t x{}, y{};
  char dir{UP};

  std::string line{};
  while (std::getline(std::cin, line)) {
    for (std::size_t i{0}; i < line.size(); ++i) {
      switch (line[i]) {
        case '#':
          line[i] = FLAG | OBSTACLE | CHECKED;
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
  while (true) {
    bool checkObstacle{false};
    std::size_t obstacleY{}, obstacleX{};
    switch (dir) {
      case UP:
        if (y > 0 && (lines[y - 1][x] & CHECKED) == 0) {
          checkObstacle = true;
          obstacleY = y - 1;
          obstacleX = x;
        }
        break;

      case RIGHT:
        if (x + 1 < lines[y].size() && (lines[y][x + 1] & CHECKED) == 0) {
          checkObstacle = true;
          obstacleY = y;
          obstacleX = x + 1;
        }
        break;

      case DOWN:
        if (y + 1 < lines.size() && (lines[y + 1][x] & CHECKED) == 0) {
          checkObstacle = true;
          obstacleY = y + 1;
          obstacleX = x;
        }
        break;

      case LEFT:
        if (x > 0 && (lines[y][x - 1] & CHECKED) == 0) {
          checkObstacle = true;
          obstacleY = y;
          obstacleX = x - 1;
        }
        break;
    }

    if (checkObstacle) {
      lines[obstacleY][obstacleX] |= OBSTACLE;

      std::stack<std::tuple<std::size_t, std::size_t, char>> steps{};
      steps.push({y, x, dir});

      bool checkDone{false};
      while (!checkDone) {
        const auto [y, x, dir] = steps.top();
        if ((lines[y][x] & dir) != 0) {
          steps.pop();
          checkDone = true;
          lines[obstacleY][obstacleX] |= CHECKED;
          ++count;
        } else {
          lines[y][x] |= dir;
          switch (dir) {
            case UP:
              if (y == 0) {
                checkDone = true;
              } else if ((lines[y - 1][x] & OBSTACLE) != 0) {
                steps.push({y, x, RIGHT});
              } else {
                steps.push({y - 1, x, dir});
              }
              break;

            case RIGHT:
              if (x == lines[y].size() - 1) {
                checkDone = true;
              } else if ((lines[y][x + 1] & OBSTACLE) != 0) {
                steps.push({y, x, DOWN});
              } else {
                steps.push({y, x + 1, dir});
              }
              break;

            case DOWN:
              if (y == lines.size() - 1) {
                checkDone = true;
              } else if ((lines[y + 1][x] & OBSTACLE) != 0) {
                steps.push({y, x, LEFT});
              } else {
                steps.push({y + 1, x, dir});
              }
              break;

            case LEFT:
              if (x == 0) {
                checkDone = true;
              } else if ((lines[y][x - 1] & OBSTACLE) != 0) {
                steps.push({y, x, UP});
              } else {
                steps.push({y, x - 1, dir});
              }
              break;
          }
        }
      }

      while (!steps.empty()) {
        const auto [y, x, dir] = steps.top();
        lines[y][x] &= ~dir;
        steps.pop();
      }

      lines[obstacleY][obstacleX] &= ~OBSTACLE;
    }

    lines[y][x] |= dir | CHECKED;

    switch (dir) {
      case UP:
        if (y == 0) {
          std::cout << count << "\n";
          return 0;
        } else if ((lines[y - 1][x] & OBSTACLE) != 0) {
          dir = RIGHT;
        } else {
          --y;
        }
        break;

      case RIGHT:
        if (x == lines[y].size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if ((lines[y][x + 1] & OBSTACLE) != 0) {
          dir = DOWN;
        } else {
          ++x;
        }
        break;

      case DOWN:
        if (y == lines.size() - 1) {
          std::cout << count << "\n";
          return 0;
        } else if ((lines[y + 1][x] & OBSTACLE) != 0) {
          dir = LEFT;
        } else {
          ++y;
        }
        break;

      case LEFT:
        if (x == 0) {
          std::cout << count << "\n";
          return 0;
        } else if ((lines[y][x - 1] & OBSTACLE) != 0) {
          dir = UP;
        } else {
          --x;
        }
        break;
    }
  }
}
