#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<bool>> map(7, std::vector<bool>(7, false));

  for (int i{12}; i > 0; --i) {
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

  for (const auto& row : map) {
    for (const auto obstacle : row) {
      std::cout << (obstacle ? "# " : ". ");
    }
    std::cout << "\n";
  }

  return 0;
}
