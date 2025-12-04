#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::string line{};
  if (!std::getline(std::cin, line)) return 1;

  std::vector<std::vector<bool>> hasPapers(
      3, std::vector<bool>(line.size() + 2, false));

  std::vector<std::vector<char>> neighbors(
      3, std::vector<char>(line.size() + 2, 0));

  for (std::size_t i{1}; true; ++i) {
    for (std::size_t j{0}; j < line.size(); ++j) {
      if (line[j] == '@') {
        hasPapers[i][j + 1] = true;

        ++neighbors[i - 1][j];
        ++neighbors[i - 1][j + 1];
        ++neighbors[i - 1][j + 2];

        ++neighbors[i][j];
        ++neighbors[i][j + 2];

        ++neighbors[i + 1][j];
        ++neighbors[i + 1][j + 1];
        ++neighbors[i + 1][j + 2];
      }
    }

    if (!std::getline(std::cin, line)) break;

    hasPapers.push_back(std::vector<bool>(line.size() + 2, false));
    neighbors.push_back(std::vector<char>(line.size() + 2, 0));
  }

  std::queue<std::tuple<std::size_t, std::size_t>> cells{};
  for (std::size_t i{0}; i < hasPapers.size(); ++i) {
    for (std::size_t j{0}; j < hasPapers[i].size(); ++j) {
      if (hasPapers[i][j] && neighbors[i][j] < 4) {
        hasPapers[i][j] = false;
        cells.push({i, j});
      }
    }
  }

  std::size_t total{cells.size()};
  while (!cells.empty()) {
    const auto [i, j] = cells.front();
    cells.pop();

    --neighbors[i - 1][j - 1];
    if (hasPapers[i - 1][j - 1] && neighbors[i - 1][j - 1] < 4) {
      hasPapers[i - 1][j - 1] = false;
      cells.push({i - 1, j - 1});
      ++total;
    }

    --neighbors[i - 1][j];
    if (hasPapers[i - 1][j] && neighbors[i - 1][j] < 4) {
      hasPapers[i - 1][j] = false;
      cells.push({i - 1, j});
      ++total;
    }

    --neighbors[i - 1][j + 1];
    if (hasPapers[i - 1][j + 1] && neighbors[i - 1][j + 1] < 4) {
      hasPapers[i - 1][j + 1] = false;
      cells.push({i - 1, j + 1});
      ++total;
    }

    --neighbors[i][j - 1];
    if (hasPapers[i][j - 1] && neighbors[i][j - 1] < 4) {
      hasPapers[i][j - 1] = false;
      cells.push({i, j - 1});
      ++total;
    }

    --neighbors[i][j + 1];
    if (hasPapers[i][j + 1] && neighbors[i][j + 1] < 4) {
      hasPapers[i][j + 1] = false;
      cells.push({i, j + 1});
      ++total;
    }

    --neighbors[i + 1][j - 1];
    if (hasPapers[i + 1][j - 1] && neighbors[i + 1][j - 1] < 4) {
      hasPapers[i + 1][j - 1] = false;
      cells.push({i + 1, j - 1});
      ++total;
    }

    --neighbors[i + 1][j];
    if (hasPapers[i + 1][j] && neighbors[i + 1][j] < 4) {
      hasPapers[i + 1][j] = false;
      cells.push({i + 1, j});
      ++total;
    }

    --neighbors[i + 1][j + 1];
    if (hasPapers[i + 1][j + 1] && neighbors[i + 1][j + 1] < 4) {
      hasPapers[i + 1][j + 1] = false;
      cells.push({i + 1, j + 1});
      ++total;
    }
  }

  std::cout << total << "\n";

  return 0;
}
