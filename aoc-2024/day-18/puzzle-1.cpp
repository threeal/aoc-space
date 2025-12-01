#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::vector<std::vector<bool>> map(71, std::vector<bool>(71, false));

  for (int i{1024}; i > 0; --i) {
    std::string line{};
    if (std::getline(std::cin, line)) {
      std::size_t i{0}, x{0}, y{0};
      while (line[i] != ',') {
        x = x * 10 + line[i] - '0';
        ++i;
      }

      ++i;
      while (line[i] != 0) {
        y = y * 10 + line[i] - '0';
        ++i;
      }

      map[y][x] = true;
    }
  }

  std::queue<std::tuple<std::size_t, std::size_t>> queue{};
  queue.push({0, 0});

  for (int steps{0}; !queue.empty(); ++steps) {
    for (std::size_t n{queue.size()}; n > 0; --n) {
      const auto [x, y] = queue.front();
      queue.pop();

      if (x == 70 && y == 70) {
        std::cout << steps << "\n";
        return 0;
      }

      if (x < 70 && !map[y][x + 1]) {
        map[y][x + 1] = true;
        queue.push({x + 1, y});
      }

      if (y < 70 && !map[y + 1][x]) {
        map[y + 1][x] = true;
        queue.push({x, y + 1});
      }

      if (x > 0 && !map[y][x - 1]) {
        map[y][x - 1] = true;
        queue.push({x - 1, y});
      }

      if (y > 0 && !map[y - 1][x]) {
        map[y - 1][x] = true;
        queue.push({x, y - 1});
      }
    }
  }

  return 1;
}
