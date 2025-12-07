#include <iostream>
#include <queue>
#include <string>

int main() {
  int count{0};

  std::string line{};
  if (std::getline(std::cin, line)) {
    std::queue<std::size_t> beams{};
    for (std::size_t i{0}; i < line.size(); ++i) {
      if (line[i] == 'S') beams.push(i);
    }

    while (std::getline(std::cin, line)) {
      for (std::size_t n{beams.size()}; n > 0; --n) {
        const std::size_t beam{beams.front()};
        beams.pop();

        switch (line[beam]) {
          case '^':
            ++count;

            if (line[beam - 1] != 'X') {
              line[beam - 1] = 'X';
              beams.push(beam - 1);
            }

            line[beam + 1] = 'X';
            beams.push(beam + 1);
            break;

          case 'X':
            break;

          default:
            line[beam] = 'X';
            beams.push(beam);
        }
      }
    }
  }

  std::cout << count << "\n";

  return 0;
}
