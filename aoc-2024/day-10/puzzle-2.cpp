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

  int total_score{0};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      if (lines[y][x] != '0') continue;

      std::queue<std::tuple<std::size_t, std::size_t>> queue{};
      queue.push({y, x});

      char level{'0'};
      while (level < '9' && !queue.empty()) {
        for (std::size_t i{queue.size()}; i > 0; --i) {
          const auto [y, x] = queue.front();
          queue.pop();

          if (x < lines[y].size() - 1 && lines[y][x + 1] == level + 1) {
            queue.push({y, x + 1});
          }

          if (y < lines.size() - 1 && lines[y + 1][x] == level + 1) {
            queue.push({y + 1, x});
          }

          if (x > 0 && lines[y][x - 1] == level + 1) {
            queue.push({y, x - 1});
          }

          if (y > 0 && lines[y - 1][x] == level + 1) {
            queue.push({y - 1, x});
          }
        }
        ++level;
      }

      if (level == '9') total_score += queue.size();
    }
  }

  std::cout << total_score << "\n";
  return 0;
}
