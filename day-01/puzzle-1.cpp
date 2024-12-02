#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::vector<int> first{}, second{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);

    int num{};
    iss >> num;
    first.push_back(num);

    iss >> num;
    second.push_back(num);
  }

  std::ranges::sort(first);
  std::ranges::sort(second);

  int total{0};
  for (std::size_t i{0}; i < first.size(); ++i) {
    total += std::abs(first[i] - second[i]);
  }

  std::cout << total << "\n";

  return 0;
}
