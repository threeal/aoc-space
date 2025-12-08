#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <string>

class Tree {
 private:
  std::size_t idx;
  std::array<int, 3> coordinate;
  std::unique_ptr<Tree> left;
  std::unique_ptr<Tree> right;

 public:
  Tree(
      std::vector<std::array<int, 3>>& coordinates,
      std::size_t l, std::size_t r, std::size_t axis)
        : idx{l + (r - l) / 2} {
    std::sort(
        coordinates.begin() + l, coordinates.begin() + r + 1,
        [axis](const std::array<int, 3>& a, const std::array<int, 3>& b) {
          return a[axis] < b[axis];
        });

    coordinate = coordinates[idx];

    if (l < idx) {
      left = std::make_unique<Tree>(coordinates, l, idx - 1, (axis + 1) % 3);
    }

    if (r > idx) {
      right = std::make_unique<Tree>(coordinates, idx + 1, r, (axis + 1) % 3);
    }
  }

  void query(
      const std::array<int, 3>& target, std::size_t axis,
      std::size_t& bestIdx, int& bestDistance) const {
    // std::cout << " " << idx << " " << coordinate[0] << " " << coordinate[1] << " " << coordinate[2] << "\n";

    const int distance{
        (target[0] - coordinate[0]) * (target[0] - coordinate[0]) +
        (target[1] - coordinate[1]) * (target[1] - coordinate[1]) +
        (target[2] - coordinate[2]) * (target[2] - coordinate[2])};

    if (distance > 0 && distance < bestDistance) {
      bestIdx = idx;
      bestDistance = distance;
    }

    const int diff{target[axis] - coordinate[axis]};
    if (diff <= 0) {
      if (left) {
        left->query(target, (axis + 1) % 3, bestIdx, bestDistance);
      }

      if (right && diff * diff < bestDistance) {
        right->query(target, (axis + 1) % 3, bestIdx, bestDistance);
      }
    } else {
      if (right) {
        right->query(target, (axis + 1) % 3, bestIdx, bestDistance);
      }

      if (left && diff * diff < bestDistance) {
        left->query(target, (axis + 1) % 3, bestIdx, bestDistance);
      }
    }
  }
};

static std::size_t rootOf(std::vector<std::size_t>& roots, std::size_t i) {
  return roots[i] == i ? i : (roots[i] = rootOf(roots, roots[i]));
}

int main() {
  std::vector<std::array<int, 3>> coordinates{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::array<int, 3> coordinate{};

    std::size_t i{0};
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

  std::vector<std::size_t> roots(coordinates.size());
  std::iota(roots.begin(), roots.end(), 0);

  const Tree tree(coordinates, 0, coordinates.size() - 1, 0);
  for (std::size_t i{0}; i < coordinates.size(); ++i) {
    std::size_t bestIdx{};
    int bestDistance{std::numeric_limits<int>::max()};
    tree.query(coordinates[i], 0, bestIdx, bestDistance);

    std::cout << i << " " << bestIdx << " " << coordinates[i][0] << " " << coordinates[i][1] << " " << coordinates[i][2] << "\n";

    const std::size_t rootOfI{rootOf(roots, i)};
    const std::size_t rootOfBestIdx{rootOf(roots, bestIdx)};
    if (rootOfI != rootOfBestIdx) {
      if (rootOfI < rootOfBestIdx) {
        roots[rootOfBestIdx] = rootOfI;
      } else {
        roots[rootOfI] = rootOfBestIdx;
      }
    }
  }

  std::vector<int> rootSizes(roots.size());
  for (std::size_t i{0}; i < roots.size(); ++i) {
    ++rootSizes[rootOf(roots, i)];
  }

  for (const int size : rootSizes) {
    std::cout << size << " ";
  }
  std::cout << "\n";

  std::partial_sort(
      rootSizes.begin(), rootSizes.begin() + 3, rootSizes.end(),
      std::greater<int>());

  std::cout << rootSizes[0] * rootSizes[1] * rootSizes[2] << "\n";

  return 0;
}
