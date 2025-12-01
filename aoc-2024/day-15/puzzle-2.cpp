#include <iostream>
#include <string>
#include <vector>

static bool checkBoxes(
    const std::vector<std::string>& lines,
    std::size_t y, std::size_t x, std::size_t dir) {
  if (lines[y][x] == '#' || lines[y][x + 1] == '#') return false;
  if (lines[y][x] == '[') return checkBoxes(lines, y + dir, x, dir);
  if (lines[y][x] == ']' && !checkBoxes(lines, y + dir, x - 1, dir)) {
    return false;
  }
  if (lines[y][x + 1] == '[' && !checkBoxes(lines, y + dir, x + 1, dir)) {
    return false;
  }
  return true;
}

static void moveBoxes(
    std::vector<std::string>& lines,
    std::size_t y, std::size_t x, std::size_t dir) {
  if (lines[y][x] == '[') {
    moveBoxes(lines, y + dir, x, dir);
    lines[y + dir][x] = '[';
    lines[y + dir][x + 1] = ']';
    lines[y][x] = '.';
    lines[y][x + 1] = '.';
  } else {
    if (lines[y][x] == ']') {
      moveBoxes(lines, y + dir, x - 1, dir);
      lines[y + dir][x - 1] = '[';
      lines[y + dir][x] = ']';
      lines[y][x - 1] = '.';
      lines[y][x] = '.';
    }
    if (lines[y][x + 1] == '[') {
      moveBoxes(lines, y + dir, x + 1, dir);
      lines[y + dir][x + 1] = '[';
      lines[y + dir][x + 2] = ']';
      lines[y][x + 1] = '.';
      lines[y][x + 2] = '.';
    }
  }
}

int main() {
  std::size_t ry{0}, rx{0};

  std::string line{};
  std::vector<std::string> lines{};
  while (std::getline(std::cin, line) && !line.empty()) {
    const std::size_t n{line.size()};
    line.resize(2 * n);

    for (std::size_t i{n}; i > 0; --i) {
      const std::size_t ii{i - 1};
      switch (line[ii]) {
        case 'O':
          line[2 * ii] = '[';
          line[2 * ii + 1] = ']';
          break;

        case '@':
          ry = lines.size();
          rx = ii * 2;
          line[ii] = '.';

        default:
          line[2 * ii] = line[ii];
          line[2 * ii + 1] = line[ii];
          break;
      }
    }

    lines.push_back(line);
  }

  while (std::getline(std::cin, line)) {
    for (const auto c : line) {
      std::size_t x{}, y{};
      switch (c) {
        case '^':
          switch (lines[ry - 1][rx]) {
            case '.':
              --ry;
              break;

            case ']':
              if (checkBoxes(lines, ry - 1, rx - 1, -1)) {
                moveBoxes(lines, ry - 1, rx - 1, -1);
                --ry;
              }
              break;

            case '[':
              if (checkBoxes(lines, ry - 1, rx, -1)) {
                moveBoxes(lines, ry - 1, rx, -1);
                --ry;
              }
              break;
          }
          break;

        case 'v':
          switch (lines[ry + 1][rx]) {
            case '.':
              ++ry;
              break;

            case ']':
              if (checkBoxes(lines, ry + 1, rx - 1, 1)) {
                moveBoxes(lines, ry + 1, rx - 1, 1);
                ++ry;
              }
              break;

            case '[':
              if (checkBoxes(lines, ry + 1, rx, 1)) {
                moveBoxes(lines, ry + 1, rx, 1);
                ++ry;
              }
              break;
          }
          break;

        case '<':
          x = rx - 1;
          while (lines[ry][x] == ']') x -= 2;
          if (lines[ry][x] == '.') {
            while (x < rx - 1) {
              lines[ry][x++] = '[';
              lines[ry][x++] = ']';
            }
            lines[ry][--rx] = '.';
          }
          break;

        case '>':
          x = rx + 1;
          while (lines[ry][x] == '[') x += 2;
          if (lines[ry][x] == '.') {
            while (x > rx + 1) {
              lines[ry][x--] = ']';
              lines[ry][x--] = '[';
            }
            lines[ry][++rx] = '.';
          }
          break;
      }
    }
  }

  std::size_t sum{0};
  for (std::size_t y{0}; y < lines.size(); ++y) {
    for (std::size_t x{0}; x < lines[y].size(); ++x) {
      if (lines[y][x] == '[') sum += 100 * y + x;
    }
  }

  std::cout << sum << "\n";
  return 0;
}
