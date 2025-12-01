#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

int main() {
  std::string line{};
  if (!std::getline(std::cin, line)) return 1;

  std::list<std::string> patterns{};

  std::size_t pos{0}, next_pos{};
  while ((next_pos = line.find(',', pos)) != std::string::npos) {
    patterns.push_back(line.substr(pos, next_pos - pos));
    pos = next_pos + 2;
  }
  patterns.push_back(line.substr(pos));

  if (!std::getline(std::cin, line)) return 1;

  std::unordered_map<std::string, std::size_t> cache{};

  const std::function<std::size_t(const std::string&)> count_permutation =
      [&](const std::string& design) -> std::size_t {
    const auto it = cache.find(design);
    if (it != cache.end()) return it->second;

    std::size_t count{0};
    for (const auto& pattern : patterns) {
      if (design.size() < pattern.size()) continue;
      if (design.compare(0, pattern.size(), pattern) == 0) {
        if (design.size() > pattern.size()) {
          count += count_permutation(design.substr(pattern.size()));
        } else {
          ++count;
        }
      }
    }

    cache.emplace(design, count);
    return count;
  };

  std::size_t count{0};
  while (std::getline(std::cin, line)) {
    count += count_permutation(line);
  }

  std::cout << count << "\n";
  return 0;
}
