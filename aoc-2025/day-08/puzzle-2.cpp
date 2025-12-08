#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

static std::size_t rootOf(std::vector<std::size_t>& roots, std::size_t i) {
  return roots[i] == i ? i : (roots[i] = rootOf(roots, roots[i]));
}

int main() {
  std::vector<std::array<long long, 3>> coordinates{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::array<long long, 3> coordinate{};

    long long i{0};
    while (line[i] != ',') {
      coordinate[0] = coordinate[0] * 10 + line[i] - '0';
      ++i;
    }

    ++i;
    while (line[i] != ',') {
      coordinate[1] = coordinate[1] * 10 + line[i] - '0';
      ++i;
    }

    ++i;
    while (i < line.size()) {
      coordinate[2] = coordinate[2] * 10 + line[i] - '0';
      ++i;
    }

    coordinates.push_back(coordinate);
  }

  auto compareCoordinates =
      [](const std::tuple<long long, std::size_t, std::size_t>& a,
         const std::tuple<long long, std::size_t, std::size_t>& b) {
        return std::get<0>(a) < std::get<0>(b);
      };

  std::priority_queue<
      std::tuple<long long, std::size_t, std::size_t>,
      std::vector<std::tuple<long long, std::size_t, std::size_t>>,
      decltype(compareCoordinates)>
      coordinatePairs(compareCoordinates);

  for (std::size_t i{0}; i < coordinates.size(); ++i) {
    for (std::size_t j{i + 1}; j < coordinates.size(); ++j) {
      const long long dist{
          (coordinates[i][0] - coordinates[j][0]) *
              (coordinates[i][0] - coordinates[j][0]) +
          (coordinates[i][1] - coordinates[j][1]) *
              (coordinates[i][1] - coordinates[j][1]) +
          (coordinates[i][2] - coordinates[j][2]) *
              (coordinates[i][2] - coordinates[j][2])};

      coordinatePairs.push({dist, i, j});
      if (coordinatePairs.size() > 1000) coordinatePairs.pop();
    }
  }

  std::vector<std::size_t> roots(coordinates.size());
  std::iota(roots.begin(), roots.end(), 0);

  while (!coordinatePairs.empty()) {
    const auto [dist, i, j] = coordinatePairs.top();
    coordinatePairs.pop();

    const std::size_t rootOfI{rootOf(roots, i)};
    const std::size_t rootOfJ{rootOf(roots, j)};
    if (rootOfI != rootOfJ) {
      if (rootOfI < rootOfJ) {
        roots[rootOfJ] = rootOfI;
      } else {
        roots[rootOfI] = rootOfJ;
      }
    }
  }

  std::vector<int> rootSizes(roots.size());
  for (std::size_t i{0}; i < roots.size(); ++i) {
    ++rootSizes[rootOf(roots, i)];
  }

  std::partial_sort(
      rootSizes.begin(), rootSizes.begin() + 3, rootSizes.end(),
      std::greater<int>());

  std::cout << rootSizes[0] * rootSizes[1] * rootSizes[2] << "\n";

  return 1;
}
