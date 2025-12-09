#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::vector<std::tuple<long long, long long>> coords{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{0};
    long long x{0};
    while (line[i] != ',') {
      x = x * 10 + line[i] - '0';
      ++i;
    }

    ++i;
    long long y{0};
    while (line[i] != 0) {
      y = y * 10 + line[i] - '0';
      ++i;
    }

    coords.push_back({x, y});
  }

  long long largestArea{0};
  for (std::size_t i{0}; i < coords.size(); ++i) {
    for (std::size_t j{0}; j < coords.size(); ++j) {
      const long long dy = std::get<0>(coords[i]) + 1 - std::get<0>(coords[j]);
      const long long dx = std::get<1>(coords[i]) + 1 - std::get<1>(coords[j]);
      const long long area{std::abs(dy * dx)};
      if (area > largestArea) largestArea = area;
    }
  }

  std::cout << largestArea << "\n";

  return 0;
}
