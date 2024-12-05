#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
  std::vector<std::unordered_set<int>> forbiddens(100);

  std::string line{};
  while (std::getline(std::cin, line) && !line.empty()) {
    const int a = (line[0] - '0') * 10 + line[1] - '0';
    const int b = (line[3] - '0') * 10 + line[4] - '0';

    forbiddens[a].insert(b);
  }

  int total{0};
  while (std::getline(std::cin, line)) {
    std::vector<int> nums{};
    nums.reserve((line.size() + 1) / 3);

    for (std::size_t i{0}; i <= line.size(); i += 3) {
      nums.push_back((line[i] - '0') * 10 + line[i + 1] - '0');
    }

    for (std::size_t i{1}; i < nums.size(); ++i) {
      for (std::size_t j{0}; j < i; ++j) {
        if (forbiddens[nums[i]].contains(nums[j])) goto skip;
      }
    }

    total += nums[nums.size() / 2];
    continue;

  skip:;
  }

  std::cout << total << "\n";
  return 0;
}
