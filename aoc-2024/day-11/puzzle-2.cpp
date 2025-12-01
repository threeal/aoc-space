#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

std::unordered_map<long long, long long> cache[75];

long long process(long long num, int time) {
  if (time == 0) return 1;

  auto it = cache[time - 1].find(num);
  if (it != cache[time - 1].end()) return it->second;

  long long count{};
  if (num == 0) {
    count = process(1, time - 1);
  } else {
    long long a{num}, b{0}, exp{1};
    while (a >= exp) {
      b += (a % 10) * exp;
      a /= 10;
      exp *= 10;
    }

    if (a >= exp / 10) {
      count = process(a, time - 1) + process(b, time - 1);
    } else {
      count = process(num * 2024, time - 1);
    }
  }

  cache[time - 1].emplace(num, count);
  return count;
}

int main() {
  std::string line{};
  std::getline(std::cin, line);

  long long count{0};
  long long num{0};
  for (std::size_t i{0}; i <= line.size(); ++i) {
    if (line[i] >= '0') {
      num = num * 10 + line[i] - '0';
    } else {
      count += process(num, 75);
      num = 0;
    }
  }

  std::cout << count << "\n";
  return 0;
}
