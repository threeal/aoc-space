#include <iostream>
#include <list>
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

      std::vector<std::list<std::tuple<std::size_t, std::size_t>>> level_queues(10);

      level_queues[0].push_back({y, x});
      lines[y][x] += 10;

      for (std::size_t i{0}; i < 9; ++i) {
        for (const auto& [y, x] : level_queues[i]) {
          if (x < lines[y].size() - 1 && lines[y][x + 1] == '1' + i) {
            level_queues[i + 1].push_back({y, x + 1});
            lines[y][x + 1] += 10;
          }

          if (y < lines.size() - 1 && lines[y + 1][x] == '1' + i) {
            level_queues[i + 1].push_back({y + 1, x});
            lines[y + 1][x] += 10;
          }

          if (x > 0 && lines[y][x - 1] == '1' + i) {
            level_queues[i + 1].push_back({y, x - 1});
            lines[y][x - 1] += 10;
          }

          if (y > 0 && lines[y - 1][x] == '1' + i) {
            level_queues[i + 1].push_back({y - 1, x});
            lines[y - 1][x] += 10;
          }
        }
      }

      total_score += level_queues[9].size();

      for (const auto& queues : level_queues) {
        for (const auto& [y, x] : queues) {
          lines[y][x] -= 10;
        }
      }
    }
  }

  std::cout << total_score << "\n";
  return 0;
}
