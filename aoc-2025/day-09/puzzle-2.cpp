#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Coord {
  long long x;
  long long y;
};

int main() {
  std::vector<Coord> coords{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    Coord coord{.x = 0, .y = 0};

    std::size_t i{0};
    while (line[i] != ',') {
      coord.x = coord.x * 10 + line[i] - '0';
      ++i;
    }

    ++i;
    while (line[i] != 0) {
      coord.y = coord.y * 10 + line[i] - '0';
      ++i;
    }

    coords.push_back(coord);
  }

  int largestArea{0};
  for (std::size_t i{0}; i < coords.size(); ++i) {
    for (std::size_t j{i + 1}; j < coords.size(); ++j) {
      const Coord a{
          .x = std::min(coords[i].x, coords[j].x),
          .y = std::min(coords[i].y, coords[j].y)};

      const Coord b{
          .x = std::max(coords[i].x, coords[j].x),
          .y = std::max(coords[i].y, coords[j].y)};

      long long area{(b.x + 1 - a.x) * (b.y + 1 - a.y)};
      if (area > largestArea) {
        bool isValid{true};
        for (std::size_t k{0}; k < coords.size(); ++k) {
          const Coord aa{
              .x = std::min(coords[k].x, coords[(k + 1) % coords.size()].x),
              .y = std::min(coords[k].y, coords[(k + 1) % coords.size()].y)};

          const Coord bb{
              .x = std::max(coords[k].x, coords[(k + 1) % coords.size()].x),
              .y = std::max(coords[k].y, coords[(k + 1) % coords.size()].y)};

          if (aa.x < b.x && bb.x > a.x && aa.y < b.y && bb.y > a.y) {
            isValid = false;
            break;
          }
        }

        if (isValid) {
          largestArea = area;
        }
      }
    }
  }

  std::cout << largestArea << "\n";

  return 0;
}
