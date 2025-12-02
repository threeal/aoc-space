#include <iostream>
#include <string>

int main() {
  std::string line{};
  std::getline(std::cin, line);

  long long sum{0};
  std::size_t i{0};
  while (i < line.size()) {
    int length{0};
    long long firstId{0};
    while (line[i] != '-') {
      ++length;
      firstId = firstId * 10 + line[i] - '0';
      ++i;
    }

    if (length % 2 == 1) {
      firstId = 1;
      for (int i{0}; i < length; ++i) firstId *= 10;
    }

    long long exp{1};
    for (length = (length + 1) / 2; length != 0; --length) exp *= 10;

    long long num{firstId / exp};
    while (num * exp + num < firstId) {
      if (++num >= exp) exp *= 10;
    }

    ++i;

    long long lastId{0};
    while (i < line.size() && line[i] != ',') {
      lastId = lastId * 10 + line[i] - '0';
      ++i;
    }

    while (num * exp + num <= lastId) {
      sum += num * exp + num;
      if (++num >= exp) exp *= 10;
    }

    ++i;
  }

  std::cout << sum << "\n";

  return 0;
}
