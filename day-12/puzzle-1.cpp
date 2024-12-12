#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  int price{0};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      if (lines[y][x] == '#') continue;

      const char plant = lines[y][x];
      int area{0}, perimeter{0};

      std::queue<std::tuple<std::size_t, std::size_t>> steps{};

      lines[y][x] = '@';
      steps.push({y, x});

      while (!steps.empty()) {
        const auto [y, x] = steps.front();
        ++area;

        if (y > 0) {
          if (lines[y - 1][x] == plant) {
            lines[y - 1][x] = '@';
            steps.push({y - 1, x});
          } else if (lines[y - 1][x] != '@') {
            ++perimeter;
          }
        } else {
          ++perimeter;
        }

        if (x > 0) {
          if (lines[y][x - 1] == plant) {
            lines[y][x - 1] = '@';
            steps.push({y, x - 1});
          } else if (lines[y][x - 1] != '@') {
            ++perimeter;
          }
        } else {
          ++perimeter;
        }

        if (y < lines.size() - 1) {
          if (lines[y + 1][x] == plant) {
            lines[y + 1][x] = '@';
            steps.push({y + 1, x});
          } else if (lines[y + 1][x] != '@') {
            ++perimeter;
          }
        } else {
          ++perimeter;
        }

        if (x < lines[y].size() - 1) {
          if (lines[y][x + 1] == plant) {
            lines[y][x + 1] = '@';
            steps.push({y, x + 1});
          } else if (lines[y][x + 1] != '@') {
            ++perimeter;
          }
        } else {
          ++perimeter;
        }

        steps.pop();
      }

      price += area * perimeter;

      lines[y][x] = '#';
      steps.push({y, x});

      while (!steps.empty()) {
        const auto [y, x] = steps.front();

        if (y > 0 && lines[y - 1][x] == '@') {
          lines[y - 1][x] = '#';
          steps.push({y - 1, x});
        }

        if (x > 0 && lines[y][x - 1] == '@') {
          lines[y][x - 1] = '#';
          steps.push({y, x - 1});
        }

        if (y < lines.size() - 1 && lines[y + 1][x] == '@') {
          lines[y + 1][x] = '#';
          steps.push({y + 1, x});
        }

        if (x < lines[y].size() - 1 && lines[y][x + 1] == '@') {
          lines[y][x + 1] = '#';
          steps.push({y, x + 1});
        }

        steps.pop();
      }
    }
  }

  std::cout << price << std::endl;
  return 0;
}
