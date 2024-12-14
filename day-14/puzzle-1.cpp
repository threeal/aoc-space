#include <iostream>
#include <string>

int main() {
  int quadrants[4] = {0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    int x{0};
    std::size_t i{2};
    while (line[i] != ',') {
      x = x * 10 + line[i] - '0';
      ++i;
    }

    int y{0};
    ++i;
    while (line[i] != ' ') {
      y = y * 10 + line[i] - '0';
      ++i;
    }

    int vx{0};
    i += 3;
    bool neg{false};
    if (line[i] == '-') {
      neg = true;
      ++i;
    }
    while (line[i] != ',') {
      vx = vx * 10 + line[i] - '0';
      ++i;
    }
    if (neg) vx = -vx;

    int vy{0};
    ++i;
    if (line[i] == '-') {
      neg = true;
      ++i;
    } else {
      neg = false;
    }
    while (line[i] != 0) {
      vy = vy * 10 + line[i] - '0';
      ++i;
    }
    if (neg) vy = -vy;

    x = (x + vx * 100) % 101;
    if (x < 0) x += 101;

    y = (y + vy * 100) % 103;
    if (y < 0) y += 103;

    if (x < 50) {
      if (y < 51) {
        ++quadrants[0];
      } else if (y > 51) {
        ++quadrants[1];
      }
    } else if (x > 50) {
      if (y < 51) {
        ++quadrants[2];
      } else if (y > 51) {
        ++quadrants[3];
      }
    }
  }

  std::cout << quadrants[0] * quadrants[1] * quadrants[2] * quadrants[3] << '\n';
  return 0;
}
