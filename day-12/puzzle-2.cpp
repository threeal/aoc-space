#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

struct Plot {
  std::size_t py;
  std::size_t px;
  std::size_t count;
};

Plot& getParent(
    std::vector<std::vector<Plot>>& plots, std::size_t y, std::size_t x) {
  Plot& plot{plots[y][x]};
  if (plot.py == y && plot.px == x) return plot;
  Plot& parent{getParent(plots, plot.py, plot.px)};
  plot.py = parent.py;
  plot.px = parent.px;
  return parent;
}

void mergeParents(
    std::vector<std::vector<Plot>>& plots,
    std::size_t y1, std::size_t x1,
    std::size_t y2, std::size_t x2) {
  Plot& p1{getParent(plots, y1, x1)};
  Plot& p2{getParent(plots, y2, x2)};
  if (p1.py != p2.py || p1.px != p2.px) {
    if (p1.py != p2.py ? p1.py <= p2.py : p1.px <= p2.px) {
      p2.py = p1.py;
      p2.px = p1.px;
      p1.count += p2.count;
    } else {
      p1.py = p2.py;
      p1.px = p2.px;
      p2.count += p1.count;
    }
  }
}

int main() {
  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  const std::size_t sy{lines.size()}, sx{lines[0].size()};
  std::vector<std::vector<Plot>> plots(sy, std::vector<Plot>(sx));
  for (std::size_t y{0}; y < sy; ++y) {
    for (std::size_t x{0}; x < sx; ++x) {
      plots[y][x].py = y;
      plots[y][x].px = x;
      plots[y][x].count = 1;
    }
  }

  for (std::size_t x{1}; x < sx; ++x) {
    if (lines[0][x - 1] == lines[0][x]) {
      mergeParents(plots, 0, x - 1, 0, x);
    }
  }

  for (std::size_t y{1}; y < sy; ++y) {
    if (lines[y - 1][0] == lines[y][0]) {
      mergeParents(plots, y - 1, 0, y, 0);
    }

    for (std::size_t x{1}; x < sx; ++x) {
      if (lines[y][x - 1] == lines[y][x]) {
        mergeParents(plots, y, x - 1, y, x);
      }

      if (lines[y - 1][x] == lines[y][x]) {
        mergeParents(plots, y - 1, x, y, x);
      }
    }
  }

  std::size_t price{0};

  price += getParent(plots, 0, 0).count;
  price += getParent(plots, sy - 1, 0).count;
  for (std::size_t x{1}; x < sx; ++x) {
    if (lines[0][x - 1] != lines[0][x]) {
      price += getParent(plots, 0, x).count;
    }

    if (lines[sy - 1][x - 1] != lines[sy - 1][x]) {
      price += getParent(plots, sy - 1, x).count;
    }
  }

  for (std::size_t y{1}; y < sy; ++y) {
    if (lines[y - 1][0] != lines[y][0]) {
      price += getParent(plots, y - 1, 0).count;
      price += getParent(plots, y, 0).count;
    }

    for (std::size_t x{1}; x < sx; ++x) {
      if (lines[y - 1][x] != lines[y][x]) {
        if (lines[y - 1][x - 1] == lines[y][x - 1] ||
            lines[y - 1][x - 1] != lines[y - 1][x]) {
          price += getParent(plots, y - 1, x).count;
        }

        if (lines[y - 1][x - 1] == lines[y][x - 1] ||
            lines[y][x - 1] != lines[y][x]) {
          price += getParent(plots, y, x).count;
        }
      }
    }
  }

  price += getParent(plots, 0, 0).count;
  price += getParent(plots, 0, sx - 1).count;
  for (std::size_t y{1}; y < sy; ++y) {
    if (lines[y - 1][0] != lines[y][0]) {
      price += getParent(plots, y, 0).count;
    }

    if (lines[y - 1][sx - 1] != lines[y][sx - 1]) {
      price += getParent(plots, y, sx - 1).count;
    }
  }

  for (std::size_t x{1}; x < sx; ++x) {
    if (lines[0][x - 1] != lines[0][x]) {
      price += getParent(plots, 0, x - 1).count;
      price += getParent(plots, 0, x).count;
    }

    for (std::size_t y{1}; y < sy; ++y) {
      if (lines[y][x - 1] != lines[y][x]) {
        if (lines[y - 1][x - 1] == lines[y - 1][x] ||
            lines[y - 1][x - 1] != lines[y][x - 1]) {
          price += getParent(plots, y, x - 1).count;
        }

        if (lines[y - 1][x - 1] == lines[y - 1][x] ||
            lines[y - 1][x] != lines[y][x]) {
          price += getParent(plots, y, x).count;
        }
      }
    }
  }

  std::cout << price << std::endl;
  return 0;
}
