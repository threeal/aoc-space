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
      if (lines[antennas[i].y][antennas[i].x] == '.') {
        lines[antennas[i].y][antennas[i].x] = '#';
        ++count;
      }

      for (std::size_t j{i + 1}; j < antennas.size(); ++j) {
        if (lines[antennas[j].y][antennas[j].x] == '.') {
          lines[antennas[j].y][antennas[j].x] = '#';
          ++count;
        }

        std::size_t ii{2}, jj{1};
        while (ii * antennas[i].x >= jj * antennas[j].x &&
               ii * antennas[i].y >= jj * antennas[j].y) {
          const std::size_t x{ii * antennas[i].x - jj * antennas[j].x};
          const std::size_t y{ii * antennas[i].y - jj * antennas[j].y};
          if (y < lines.size() && x < lines[y].size()) {
            if (lines[y][x] == '.') {
              lines[y][x] = '#';
              ++count;
            }
            ++ii;
            ++jj;
          } else {
            break;
          }
        }

        jj = 2;
        ii = 1;
        while (jj * antennas[j].x >= ii * antennas[i].x &&
               jj * antennas[j].y >= ii * antennas[i].y) {
          const std::size_t x{jj * antennas[j].x - ii * antennas[i].x};
          const std::size_t y{jj * antennas[j].y - ii * antennas[i].y};
          if (y < lines.size() && x < lines[y].size()) {
            if (lines[y][x] == '.') {
              lines[y][x] = '#';
              ++count;
            }
            ++ii;
            ++jj;
          } else {
            break;
          }
        }
      }
    }
  }

  std::cout << count << "\n";
  return 0;
}
