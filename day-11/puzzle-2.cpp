#include <iostream>
#include <list>
#include <string>

int main() {
  std::string line{};
  std::getline(std::cin, line);

  long long num{0};
  std::list<long long> nums{};
  for (std::size_t i{0}; i <= line.size(); ++i) {
    if (line[i] >= '0') {
      num = num * 10 + line[i] - '0';
    } else {
      nums.push_back(num);
      num = 0;
    }
  }

  for (std::size_t n{25}; n > 0; --n) {
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (*it == 0) {
        *it = 1;
      } else {
        long long a{*it}, b{0}, exp{1};
        while (a >= exp) {
          b += (a % 10) * exp;
          a /= 10;
          exp *= 10;
        }
        if (a >= exp / 10) {
          *it = b;
          nums.insert(it, a);
        } else {
          *it *= 2024;
        }
      }
    }
    std::cout << n << " " << nums.size() << "\n";
  }

  std::cout << nums.size() << "\n";
  return 0;
}
