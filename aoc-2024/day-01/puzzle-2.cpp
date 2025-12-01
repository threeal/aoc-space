#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> first{};
  std::unordered_map<int, int> second{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);

    int num{};
    iss >> num;
    first.push_back(num);

    iss >> num;
    auto it = second.find(num);
    if (it == second.end()) {
      second.emplace(num, 1);
    } else {
      ++(it->second);
    }
  }

  int total{0};
  for (const auto num : first) {
    const auto it = second.find(num);
    if (it != second.end()) total += num * it->second;
  }

  std::cout << total << "\n";

  return 0;
}
