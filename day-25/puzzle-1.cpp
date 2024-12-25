#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line{};
  while (std::getline(std::cin, line)) {
    if (line == "#####") {
      std::vector<int> lock(5, 0);
      while (std::getline(std::cin, line) && !line.empty()) {
        for (std::size_t i{0}; i < lock.size(); ++i) {
          if (line[i] == '#') ++lock[i];
        }
      }
      std::cout << "lock:";
      for (const auto val : lock) std::cout << " " << val;
      std::cout << "\n";
    } else if (line == ".....") {
      std::vector<int> key(5, -1);
      while (std::getline(std::cin, line) && !line.empty()) {
        for (std::size_t i{0}; i < key.size(); ++i) {
          if (line[i] == '#') ++key[i];
        }
      }
      std::cout << "key:";
      for (const auto val : key) std::cout << " " << val;
      std::cout << "\n";
    } else {
      return 1;
    }
  }
  return 1;
}
