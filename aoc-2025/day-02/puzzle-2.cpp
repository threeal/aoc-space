#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  std::string line{};
  std::getline(std::cin, line);

  long long sum{0};
  std::size_t i{0};
  while (i < line.size()) {
    long long firstId{0};
    int firstDigits{0};
    while (line[i] != '-') {
      firstId = firstId * 10 + line[i] - '0';
      ++firstDigits;
      ++i;
    }

    ++i;

    long long lastId{0};
    int lastDigits{0};
    while (i < line.size() && line[i] != ',') {
      lastId = lastId * 10 + line[i] - '0';
      ++lastDigits;
      ++i;
    }

    ++i;

    std::unordered_set<long long> visited{};
    for (int repeat{2}; repeat <= lastDigits; ++repeat) {
      int expDigits{firstDigits / repeat};
      if (firstDigits % repeat != 0) ++expDigits;

      long long exp{1};
      for (int i{expDigits}; i != 0; --i) exp *= 10;

      long long num{};
      if (firstDigits % repeat == 0) {
        num = firstId;
        for (int i{1}; i < repeat; ++i) num /= exp;
      } else {
        num = exp / 10;
      }

      long long id{num};
      for (int i{1}; i < repeat; ++i) id = id * exp + num;

      while (id < firstId) {
        if (++num >= exp) exp *= 10;

        id = num;
        for (int i{1}; i < repeat; ++i) id = id * exp + num;
      }

      while (id <= lastId) {
        if (!visited.contains(id)) {
          visited.insert(id);
          sum += id;
        }

        if (++num >= exp) exp *= 10;

        id = num;
        for (int i{1}; i < repeat; ++i) id = id * exp + num;
      }
    }
  }

  std::cout << sum << "\n";

  return 0;
}
