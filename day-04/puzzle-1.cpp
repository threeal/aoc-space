#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }
  std::size_t m{lines.size()}, n{lines.front().size()};

  int count{};

  for (std::size_t i{0}; i < m; ++i) {
    for (std::size_t j{3}; j < n; ++j) {
      if (lines[i][j - 3] == 'X' && lines[i][j - 2] == 'M' &&
          lines[i][j - 1] == 'A' && lines[i][j] == 'S') ++count;

      if (lines[i][j - 3] == 'S' && lines[i][j - 2] == 'A' &&
          lines[i][j - 1] == 'M' && lines[i][j] == 'X') ++count;
    }
  }

  for (std::size_t j{0}; j < n; ++j) {
    for (std::size_t i{3}; i < m; ++i) {
      if (lines[i - 3][j] == 'X' && lines[i - 2][j] == 'M' &&
          lines[i - 1][j] == 'A' && lines[i][j] == 'S') ++count;

      if (lines[i - 3][j] == 'S' && lines[i - 2][j] == 'A' &&
          lines[i - 1][j] == 'M' && lines[i][j] == 'X') ++count;
    }
  }

  for (std::size_t i{3}; i < m; ++i) {
    for (std::size_t j{3}; j < n; ++j) {
      if (lines[i - 3][j - 3] == 'X' && lines[i - 2][j - 2] == 'M' &&
          lines[i - 1][j - 1] == 'A' && lines[i][j] == 'S') ++count;

      if (lines[i - 3][j - 3] == 'S' && lines[i - 2][j - 2] == 'A' &&
          lines[i - 1][j - 1] == 'M' && lines[i][j] == 'X') ++count;

      if (lines[i - 3][n - j + 2] == 'X' && lines[i - 2][n - j + 1] == 'M' &&
          lines[i - 1][n - j] == 'A' && lines[i][n - j - 1] == 'S') ++count;

      if (lines[i - 3][n - j + 2] == 'S' && lines[i - 2][n - j + 1] == 'A' &&
          lines[i - 1][n - j] == 'M' && lines[i][n - j - 1] == 'X') ++count;
    }
  }

  std::cout << count << '\n';
  return 0;
}
