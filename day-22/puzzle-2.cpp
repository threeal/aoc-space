#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main() {
  std::unordered_map<std::size_t, long long> patternPrices{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    long long secret{};
    for (const auto c : line) {
      secret = secret * 10 + c - '0';
    }

    std::unordered_set<std::size_t> seenPatterns{};
    std::size_t pattern{0};

    for (std::size_t i{1}; i < 4; ++i) {
      const char prevPrice = secret % 10;
      secret = (secret ^ (secret * 64)) % 16777216;
      secret = (secret ^ (secret / 32)) % 16777216;
      secret = (secret ^ (secret * 2048)) % 16777216;
      const char price = secret % 10;

      pattern = (pattern * 20) + 10 + (price - prevPrice);
    }

    for (std::size_t n{2000 - 3}; n > 0; --n) {
      const char prevPrice = secret % 10;
      secret = (secret ^ (secret * 64)) % 16777216;
      secret = (secret ^ (secret / 32)) % 16777216;
      secret = (secret ^ (secret * 2048)) % 16777216;
      const char price = secret % 10;

      pattern = ((pattern * 20) + 10 + (price - prevPrice)) % 160000;
      if (!seenPatterns.contains(pattern)) {
        seenPatterns.insert(pattern);

        auto it = patternPrices.find(pattern);
        if (it == patternPrices.end()) {
          patternPrices.emplace(pattern, price);
        } else {
          it->second += price;
        }
      }
    }
  }

  long long maxPrice{0};
  for (const auto& [pattern, price] : patternPrices) {
    if (price > maxPrice) maxPrice = price;
  }
  std::cout << maxPrice << "\n";

  return 0;
}
