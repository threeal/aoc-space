#include <iostream>
#include <string>
#include <vector>

int main() {
  long long total{0};
  std::vector<long long> sum{}, multiply{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{0}, j{0};
    while (true) {
      while (i < line.size() && line[i] == ' ') ++i;
      if (i == line.size()) break;

      switch (line[i]) {
        case '+':
          total += sum[j];
          ++i;
          break;

        case '*':
          total += multiply[j];
          ++i;
          break;

        default: {
          long long num{0};
          while (i < line.size() && line[i] != ' ') {
            num = num * 10 + line[i] - '0';
            ++i;
          }

          if (j < sum.size()) {
            sum[j] += num;
            multiply[j] *= num;
          } else {
            sum.push_back(num);
            multiply.push_back(num);
          }
        }
      }
      ++j;
    }
  }

  std::cout << total << "\n";

  return 0;
}
