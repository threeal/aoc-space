#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int time{1};
  std::queue<std::tuple<std::size_t, std::size_t>> steps{};
  std::vector<std::vector<int>> map{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::vector<int> row(line.size());
    for (std::size_t i{0}; i < line.size(); ++i) {
      switch (line[i]) {
        case '#':
          row[i] = -1;
          break;

        case 'S':
          row[i] = time;
          steps.push({map.size(), i});
          break;

        default:
          row[i] = 0;
          break;
      }
    }
    map.push_back(row);
  }

  int count{0};
  while (!steps.empty()) {
    ++time;
    for (std::size_t n{steps.size()}; n > 0; --n) {
      const auto [y, x] = steps.front();
      steps.pop();

      switch (map[y - 1][x]) {
        case -1:
          if (y >= 2) {
            const int t{map[y - 2][x]};
            if (t > 0 && time - t - 3 >= 100) ++count;
          }
          break;

        case 0:
          map[y - 1][x] = time;
          steps.push({y - 1, x});
          break;
      }

      switch (map[y][x - 1]) {
        case -1:
          if (x >= 2) {
            const int t{map[y][x - 2]};
            if (t > 0 && time - t - 3 >= 100) ++count;
          }
          break;

        case 0:
          map[y][x - 1] = time;
          steps.push({y, x - 1});
          break;
      }

      switch (map[y + 1][x]) {
        case -1:
          if (y + 2 < map.size()) {
            const int t{map[y + 2][x]};
            if (t > 0 && time - t - 3 >= 100) ++count;
          }
          break;

        case 0:
          map[y + 1][x] = time;
          steps.push({y + 1, x});
          break;
      }

      switch (map[y][x + 1]) {
        case -1:
          if (x + 2 < map[y].size()) {
            const int t{map[y][x + 2]};
            if (t > 0 && time - t - 3 >= 100) ++count;
          }
          break;

        case 0:
          map[y][x + 1] = time;
          steps.push({y, x + 1});
          break;
      }
    }
  }

  std::cout << count << "\n";
  return 0;
}
