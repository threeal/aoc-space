#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int time{0};
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
          row[i] = time + 1;
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

      if (map[y - 1][x] == 0) {
        map[y - 1][x] = time + 1;
        steps.push({y - 1, x});
      }

      if (map[y][x - 1] == 0) {
        map[y][x - 1] = time + 1;
        steps.push({y, x - 1});
      }

      if (map[y + 1][x] == 0) {
        map[y + 1][x] = time + 1;
        steps.push({y + 1, x});
      }

      if (map[y][x + 1] == 0) {
        map[y][x + 1] = time + 1;
        steps.push({y, x + 1});
      }

      std::vector<std::vector<bool>> visited(
          map.size(), std::vector<bool>(map.front().size(), false));

      std::queue<std::tuple<std::size_t, std::size_t>> steps{};

      visited[y][x] = true;
      steps.push({y, x});

      for (int i{0}; i <= 20 && !steps.empty(); ++i) {
        for (std::size_t n{steps.size()}; n > 0; --n) {
          const auto [y, x] = steps.front();
          steps.pop();

          if (map[y][x] > 0 && time - map[y][x] - i >= 100) ++count;

          if (y > 0 && !visited[y - 1][x]) {
            visited[y - 1][x] = true;
            steps.push({y - 1, x});
          }

          if (x > 0 && !visited[y][x - 1]) {
            visited[y][x - 1] = true;
            steps.push({y, x - 1});
          }

          if (y + 1 < visited.size() && !visited[y + 1][x]) {
            visited[y + 1][x] = true;
            steps.push({y + 1, x});
          }

          if (x + 1 < visited[y].size() && !visited[y][x + 1]) {
            visited[y][x + 1] = true;
            steps.push({y, x + 1});
          }
        }
      }
    }
  }

  std::cout << count << "\n";
  return 0;
}
