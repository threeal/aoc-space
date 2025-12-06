#include <iostream>
#include <string>
#include <vector>

int main() {
  long long total{0};
  std::vector<long long> nums{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    if (line.size() > nums.size()) {
      nums.resize(line.size(), 0);
    }

    for (std::size_t i{0}; i < line.size(); ++i) {
      switch (line[i]) {
        case ' ':
          break;

        case '+': {
          long long num{nums[i]};
          while (i + 1 < nums.size() && nums[i + 1] != 0) {
            ++i;
            num += nums[i];
          }
          total += num;
          break;
        }

        case '*': {
          long long num{nums[i]};
          while (i + 1 < nums.size() && nums[i + 1] != 0) {
            ++i;
            num *= nums[i];
          }
          total += num;
          break;
        }

        default:
          nums[i] = nums[i] * 10 + line[i] - '0';
      }
    }
  }

  std::cout << total << "\n";

  return 0;
}
