#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  if (!std::getline(std::cin, line)) return 1;

  std::vector<std::vector<int>> neighbors(
      3, std::vector<int>(line.size() + 2, 0));

  for (std::size_t j{0}; j < line.size(); ++j) {
    if (line[j] == '@') {
      ++neighbors[0][j], ++neighbors[0][j + 2];
      ++neighbors[1][j], ++neighbors[1][j + 1], ++neighbors[1][j + 2];
    }
  }

  int total{0};
  std::string prevLine{line};
  std::size_t i0{0}, i1{1}, i2{2};
  while (std::getline(std::cin, line)) {
    for (std::size_t j{0}; j < line.size(); ++j) {
      if (line[j] == '@') {
        ++neighbors[i0][j], ++neighbors[i0][j + 1], ++neighbors[i0][j + 2];
        ++neighbors[i1][j], ++neighbors[i1][j + 2];
        ++neighbors[i2][j], ++neighbors[i2][j + 1], ++neighbors[i2][j + 2];
      }
    }

    for (std::size_t j{0}; j < prevLine.size(); ++j) {
      if (prevLine[j] == '@' && neighbors[i0][j + 1] < 4) ++total;
    }

    neighbors[i0].assign(neighbors[i0].size(), 0);
    std::swap(line, prevLine);

    i0 = (i0 + 1) % 3;
    i1 = (i1 + 1) % 3;
    i2 = (i2 + 1) % 3;
  }

  for (std::size_t j{0}; j < prevLine.size(); ++j) {
    if (prevLine[j] == '@' && neighbors[i0][j + 1] < 4) ++total;
  }

  std::cout << total << "\n";

  return 0;
}
