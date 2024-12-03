#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool check(const std::vector<int>& nums) {
  if (nums[1] > nums[0]) {
    if (nums[1] - nums[0] > 3) return false;
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] <= nums[i - 1] || nums[i] - nums[i - 1] > 3) return false;
    }
    return true;
  } else if (nums[1] < nums[0]) {
    if (nums[1] - nums[0] < -3) return false;
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] >= nums[i - 1] || nums[i] - nums[i - 1] < -3) return false;
    }
    return true;
  } else {
    return false;
  }
}

int main() {
  int count{0};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::vector<int> nums{};

    int num{};
    while (iss >> num) nums.push_back(num);

    if (check(nums)) {
      ++count;
    } else {
      for (std::size_t i{0}; i < nums.size(); ++i) {
        auto other = nums;
        other.erase(other.begin() + i);
        if (check(other)) {
          ++count;
          break;
        }
      }
    }
  }

  std::cout << count << "\n";

  return 0;
}
