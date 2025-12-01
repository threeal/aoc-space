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

    count += move / 100;
    move %= 100;

    if (line[0] == 'L') {
      if (move > pos) {
        if (pos != 0) ++count;
        pos = (100 + pos - move) % 100;
      } else {
        if (pos == move) ++count;
        pos -= move;
      }
    } else {
      pos += move;
      if (pos >= 100) {
        pos -= 100;
        ++count;
      }
    }
  }

  std::cout << count << "\n";

  return 0;
}
