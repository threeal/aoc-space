#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  int count{0};
  for (std::size_t i{2}; i < lines.size(); ++i) {
    for (std::size_t j{2}; j < lines.size(); ++j) {
      if (lines[i - 1][j - 1] != 'A') continue;
      if (lines[i - 2][j - 2] == 'S' && lines[i][j] == 'M') {
        if (lines[i][j - 2] == 'S' && lines[i - 2][j] == 'M') {
          ++count;
        } else if (lines[i][j - 2] == 'M' && lines[i - 2][j] == 'S') {
          ++count;
        }
      } else if (lines[i - 2][j - 2] == 'M' && lines[i][j] == 'S') {
        if (lines[i][j - 2] == 'S' && lines[i - 2][j] == 'M') {
          ++count;
        } else if (lines[i][j - 2] == 'M' && lines[i - 2][j] == 'S') {
          ++count;
        }
      }
    }
  }

  std::cout << count << "\n";
  return 0;
}
