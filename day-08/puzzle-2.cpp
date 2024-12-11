#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Pos {
  std::size_t x;
  std::size_t y;
};

int main() {
  std::unordered_map<char, std::vector<Pos>> grouped_antennas{};

  std::vector<std::string> lines{};
  std::string line{};
  while (std::getline(std::cin, line)) {
    for (std::size_t i{0}; i < line.size(); ++i) {
      if (line[i] != '.') {
        grouped_antennas[line[i]].push_back({.x = i, .y = lines.size()});
        line[i] = '.';
      }
    }
    lines.push_back(line);
  }

  int count{0};
  for (const auto& [freq, antennas] : grouped_antennas) {
    for (std::size_t i{0}; i < antennas.size(); ++i) {
      for (std::size_t j{i + 1}; j < antennas.size(); ++j) {
        if (2 * antennas[i].x >= antennas[j].x && 2 * antennas[i].y >= antennas[j].y) {
          const std::size_t x{2 * antennas[i].x - antennas[j].x};
          const std::size_t y{2 * antennas[i].y - antennas[j].y};
          if (y < lines.size() && x < lines[y].size() && lines[y][x] == '.') {
            lines[y][x] = '#';
            ++count;
          }
        }

        if (2 * antennas[j].x >= antennas[i].x && 2 * antennas[j].y >= antennas[i].y) {
          const std::size_t x{2 * antennas[j].x - antennas[i].x};
          const std::size_t y{2 * antennas[j].y - antennas[i].y};
          if (y < lines.size() && x < lines[y].size() && lines[y][x] == '.') {
            lines[y][x] = '#';
            ++count;
          }
        }
      }
    }
  }

  std::cout << count << "\n";
  return 0;
}
