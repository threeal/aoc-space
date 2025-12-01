#include <iostream>
#include <string>

int main() {
  int count{0}, pos{50};

  std::string line{};
  while (std::getline(std::cin, line)) {
    int move{0};
    for (std::size_t i{1}; i < line.size(); ++i) {
      move = move * 10 + line[i] - '0';
    }

    if (line[0] == 'L') move *= -1;

    pos = (100 + (move + pos) % 100) % 100;
    if (pos == 0) ++count;
  }

  std::cout << count << "\n";

  return 0;
}
