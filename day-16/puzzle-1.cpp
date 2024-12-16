#include <iostream>
#include <queue>
#include <string>
#include <vector>

enum {
  F_OBSTACLE = 1,
  F_RIGHT = 2,
  F_DOWN = 4,
  F_LEFT = 8,
  F_UP = 16,
};

struct Step {
  int point;
  std::size_t y;
  std::size_t x;
  char dir;
};

struct CompareSteps {
  bool operator()(const Step& a, const Step& b) {
    return a.point > b.point;
  }
};

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  std::size_t sy{}, sx{}, ey{}, ex{};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      switch (lines[y][x]) {
        case '#':
          lines[y][x] = F_OBSTACLE;
          break;

        case 'S':
          sy = y;
          sx = x;
          lines[y][x] = 0;
          break;

        case 'E':
          ey = y;
          ex = x;
          lines[y][x] = 0;
          break;

        default:
          lines[y][x] = 0;
      }
    }
  }

  std::priority_queue<Step, std::vector<Step>, CompareSteps> steps{};
  steps.push({0, sy, sx, F_RIGHT});

  while (!steps.empty()) {
    const auto step = steps.top();
    if (step.y == ey && step.x == ex) {
      std::cout << step.point << "\n";
      return 0;
    }
    steps.pop();

    switch (step.dir) {
      case F_RIGHT:
        if ((lines[step.y][step.x] & F_RIGHT) != 0) continue;
        lines[step.y][step.x] |= F_RIGHT;

        if ((lines[step.y][step.x + 1] & (F_OBSTACLE | F_RIGHT)) == 0) {
          steps.push({step.point + 1, step.y, step.x + 1, F_RIGHT});
        }

        if ((lines[step.y][step.x] & F_DOWN) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_DOWN});
        }

        if ((lines[step.y][step.x] & F_UP) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_UP});
        }
        break;

      case F_DOWN:
        if ((lines[step.y][step.x] & F_DOWN) != 0) continue;
        lines[step.y][step.x] |= F_DOWN;

        if ((lines[step.y + 1][step.x] & (F_OBSTACLE | F_DOWN)) == 0) {
          steps.push({step.point + 1, step.y + 1, step.x, F_DOWN});
        }

        if ((lines[step.y][step.x] & F_LEFT) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_LEFT});
        }

        if ((lines[step.y][step.x] & F_RIGHT) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_RIGHT});
        }
        break;

      case F_LEFT:
        if ((lines[step.y][step.x] & F_LEFT) != 0) continue;
        lines[step.y][step.x] |= F_LEFT;

        if ((lines[step.y][step.x - 1] & (F_OBSTACLE | F_LEFT)) == 0) {
          steps.push({step.point + 1, step.y, step.x - 1, F_LEFT});
        }

        if ((lines[step.y][step.x] & F_UP) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_UP});
        }

        if ((lines[step.y][step.x] & F_DOWN) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_DOWN});
        }
        break;

      case F_UP:
        if ((lines[step.y][step.x] & F_UP) != 0) continue;
        lines[step.y][step.x] |= F_UP;

        if ((lines[step.y - 1][step.x] & (F_OBSTACLE | F_UP)) == 0) {
          steps.push({step.point + 1, step.y - 1, step.x, F_UP});
        }

        if ((lines[step.y][step.x] & F_RIGHT) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_RIGHT});
        }

        if ((lines[step.y][step.x] & F_LEFT) == 0) {
          steps.push({step.point + 1000, step.y, step.x, F_LEFT});
        }
        break;
    }
  }

  return 1;
}
