#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::string line{};
  std::vector<std::tuple<long long, long long>> ranges{};
  while (std::getline(std::cin, line) && !line.empty()) {
    std::size_t i{0};
    long long start{0};
    while (line[i] != '-') {
      start = start * 10 + line[i] - '0';
      ++i;
    }

    long long end{0};
    while (++i < line.size()) {
      end = end * 10 + line[i] - '0';
    }

    ranges.push_back({start, end});
  }

  std::sort(
      ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        return std::get<0>(a) == std::get<0>(b)
                   ? std::get<1>(a) < std::get<1>(b)
                   : std::get<0>(a) > std::get<0>(b);
      });

  std::vector<long long> ingredients{};
  while (std::getline(std::cin, line)) {
    long long ingredient{0};
    for (std::size_t i{0}; i < line.size(); ++i) {
      ingredient = ingredient * 10 + line[i] - '0';
    }
    ingredients.push_back(ingredient);
  }

  std::sort(ingredients.begin(), ingredients.end());

  int count{0};
  for (const long long ingredient : ingredients) {
    while (!ranges.empty() && std::get<1>(ranges.back()) < ingredient) {
      ranges.pop_back();
    }

    if (ranges.empty()) break;
    if (ingredient >= std::get<0>(ranges.back())) ++count;
  }

  std::cout << count << "\n";

  return 0;
}
