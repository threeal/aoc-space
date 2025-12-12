#include <iostream>
#include <string>

int main() {
  int mw{0}, mh{0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    if (line.back() != ':') break;

    int h{0};
    while (std::getline(std::cin, line)) {
      if (line.empty()) break;

      const int w = line.size();
      if (w > mw) mw = w;
      ++h;
    }

    if (h > mh) mh = h;
  }

  int fits{0};
  do {
    std::size_t i{0};

    int w{0};
    while (line[i] != 'x') {
      w = w * 10 + line[i] - '0';
      ++i;
    }
    ++i;

    int h{0};
    while (line[i] != ':') {
      h = h * 10 + line[i] - '0';
      ++i;
    }
    i += 2;

    int totalPresents{0};
    while (i < line.size()) {
      int present{0};
      while (i < line.size() && line[i] != ' ') {
        present = present * 10 + line[i] - '0';
        ++i;
      }
      totalPresents += present;
      ++i;
    }

    if (totalPresents <= (w / mw) * (h / mh)) ++fits;
  } while (std::getline(std::cin, line));

  std::cout << fits << "\n";

  return 0;
}
