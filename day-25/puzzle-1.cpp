#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  int count{0};

  std::list<std::vector<int>> locks{}, keys{};
  std::string line{};
  while (std::getline(std::cin, line)) {
    if (line == "#####") {
      std::vector<int> lock(5, 0);
      while (std::getline(std::cin, line) && !line.empty()) {
        for (std::size_t i{0}; i < lock.size(); ++i) {
          if (line[i] == '#') ++lock[i];
        }
      }

      for (const auto& key : keys) {
        if (lock[0] + key[0] > 5) continue;
        if (lock[1] + key[1] > 5) continue;
        if (lock[2] + key[2] > 5) continue;
        if (lock[3] + key[3] > 5) continue;
        if (lock[4] + key[4] > 5) continue;
        ++count;
      }

      locks.push_back(lock);
    } else if (line == ".....") {
      std::vector<int> key(5, -1);
      while (std::getline(std::cin, line) && !line.empty()) {
        for (std::size_t i{0}; i < key.size(); ++i) {
          if (line[i] == '#') ++key[i];
        }
      }

      for (const auto& lock : locks) {
        if (lock[0] + key[0] > 5) continue;
        if (lock[1] + key[1] > 5) continue;
        if (lock[2] + key[2] > 5) continue;
        if (lock[3] + key[3] > 5) continue;
        if (lock[4] + key[4] > 5) continue;
        ++count;
      }

      keys.push_back(key);
    } else {
      return 1;
    }
  }

  std::cout << count << "\n";
  return 0;
}
