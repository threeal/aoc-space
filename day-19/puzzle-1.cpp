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

  std::unordered_map<std::string, bool> cache{};

  const std::function<bool(const std::string&)> is_valid =
      [&](const std::string& design) -> bool {
    const auto it = cache.find(design);
    if (it != cache.end()) return it->second;

    for (const auto& pattern : patterns) {
      if (design.size() < pattern.size()) continue;
      if (design.compare(0, pattern.size(), pattern) == 0) {
        if (design.size() > pattern.size() &&
            !is_valid(design.substr(pattern.size()))) continue;

        cache.emplace(design, true);
        return true;
      }
    }

    cache.emplace(design, false);
    return false;
  };

  int count{0};
  while (std::getline(std::cin, line)) {
    if (is_valid(line)) ++count;
  }

  std::cout << count << "\n";
  return 0;
}
