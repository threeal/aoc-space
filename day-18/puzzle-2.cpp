#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::vector<std::tuple<std::size_t, std::size_t>> bytes{};

  std::string line{};
  while (std::getline(std::cin, line)) {
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

    bytes.push_back({x, y});
  }

  std::size_t low{0}, high{bytes.size() - 1};
  while (low < high) {
    const std::size_t mid{low + (high - low) / 2};

    std::vector<std::vector<bool>> map(71, std::vector<bool>(71, false));
    for (std::size_t i{0}; i <= mid; ++i) {
      map[std::get<1>(bytes[i])][std::get<0>(bytes[i])] = true;
    }

    std::queue<std::tuple<std::size_t, std::size_t>> queue{};
    queue.push({0, 0});

    bool pathExist{false};
    for (int steps{0}; !queue.empty(); ++steps) {
      for (std::size_t n{queue.size()}; n > 0; --n) {
        const auto [x, y] = queue.front();
        queue.pop();

        if (x == 70 && y == 70) {
          pathExist = true;
          while (!queue.empty()) queue.pop();
          n = 1;
          break;
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

    if (pathExist) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  std::cout << std::get<0>(bytes[low]) << "," << std::get<1>(bytes[low]) << "\n";
  return 0;
}
