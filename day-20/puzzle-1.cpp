#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> map{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    map.push_back(line);
  }

  std::size_t sy{}, sx{}, ey{}, ex{};
  for (std::size_t y{0}; y < map.size(); ++y) {
    for (std::size_t x{0}; x < map[y].size(); ++x) {
      switch (map[y][x]) {
        case 'S':
          map[y][x] = '.';
          sy = y;
          sx = x;
          break;

        case 'E':
          map[y][x] = '.';
          ey = y;
          ex = x;
          break;
      }
    }
  }

  for (const auto& line : map) {
    std::cout << line << "\n";
  }
  std::cout << sx << " " << sy << "\n";
  std::cout << ex << " " << ey << "\n";

  return 1;
}
