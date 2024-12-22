#include <iostream>
#include <string>

int main() {
  std::size_t sum{0};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t secret{};
    for (const auto c : line) {
      secret = secret * 10 + c - '0';
    }

    for (std::size_t n{2000}; n > 0; --n) {
      secret = (secret ^ (secret * 64)) % 16777216;
      secret = (secret ^ (secret / 32)) % 16777216;
      secret = (secret ^ (secret * 2048)) % 16777216;
    }

    sum += secret;
  }

  std::cout << sum << "\n";
  return 1;
}
