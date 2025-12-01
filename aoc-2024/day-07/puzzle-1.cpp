#include <iostream>
#include <queue>
#include <string>

int main() {
  long long total{0};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{0};

    long long test{0};
    while (line[i] != ':') {
      test = test * 10 + line[i] - '0';
      ++i;
    }

    ++i;
    while (line[i] < '0') ++i;

    long long num{0};
    while (line[i] >= '0') {
      num = num * 10 + line[i] - '0';
      ++i;
    }

    std::queue<long long> nums{};
    nums.push(num);

    while (i < line.size()) {
      while (line[i] < '0') ++i;

      num = 0;
      while (line[i] >= '0') {
        num = num * 10 + line[i] - '0';
        ++i;
      }

      for (std::size_t n{nums.size()}; n > 0; --n) {
        if (nums.front() + num <= test) nums.push(nums.front() + num);
        if (nums.front() * num <= test) nums.push(nums.front() * num);
        nums.pop();
      }
    }

    while (!nums.empty()) {
      if (nums.front() == test) {
        total += test;
        break;
      }
      nums.pop();
    }
  }

  std::cout << total << "\n";
  return 0;
}
