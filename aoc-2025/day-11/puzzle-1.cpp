#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

static int explore(
    std::unordered_map<std::string, int>& cache,
    const std::unordered_map<std::string, std::vector<std::string>>& devices,
    const std::string& device) {
  auto cacheIt = cache.find(device);
  if (cacheIt == cache.end()) {
    int count{0};
    const auto it = devices.find(device);
    if (it != devices.end()) {
      for (const std::string& next : it->second) {
        if (next == "out") {
          ++count;
        } else {
          count += explore(cache, devices, next);
        }
      }
    }

    cacheIt = cache.emplace(device, count).first;
  }

  return cacheIt->second;
}

int main() {
  std::unordered_map<std::string, std::vector<std::string>> devices{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t l{0}, r{0};
    while (line[r] != ':') ++r;
    const std::string device{line.substr(l, r - l)};

    std::vector<std::string> nexts{};

    r += 2;
    while (r < line.size()) {
      l = r;
      while (r < line.size() && line[r] != ' ') ++r;
      nexts.push_back(std::move(line.substr(l, r - l)));
      ++r;
    }

    devices.emplace(std::move(device), std::move(nexts));
  }

  std::unordered_map<std::string, int> cache{};
  std::cout << explore(cache, devices, "you") << "\n";

  return 0;
}
