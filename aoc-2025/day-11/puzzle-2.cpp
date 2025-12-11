#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

static long long explore(
    std::array<std::unordered_map<std::string, long long>, 4>& cache,
    const std::unordered_map<std::string, std::vector<std::string>>& devices,
    const std::string& device, char flag) {
  if (device == "dac") flag |= 1;
  if (device == "fft") flag |= 2;

  auto cacheIt = cache[flag].find(device);
  if (cacheIt == cache[flag].end()) {
    long long count{0};
    const auto it = devices.find(device);
    if (it != devices.end()) {
      for (const std::string& next : it->second) {
        if (next == "out" && flag == 3) {
          ++count;
        } else {
          count += explore(cache, devices, next, flag);
        }
      }
    }

    cacheIt = cache[flag].emplace(device, count).first;
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

  std::array<std::unordered_map<std::string, long long>, 4> cache{};
  std::cout << explore(cache, devices, "svr", 0) << "\n";

  return 0;
}
