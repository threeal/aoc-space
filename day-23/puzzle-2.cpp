#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main() {
  int count{0};
  std::unordered_map<std::string, std::unordered_set<std::string>> connections{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    const auto delimiter = line.find('-');
    const auto a = line.substr(0, delimiter);
    const auto b = line.substr(delimiter + 1);

    for (const auto& c : connections[a]) {
      if (a[0] != 't' && b[0] != 't' && c[0] != 't') continue;
      if (connections[c].contains(b)) ++count;
    }

    connections[a].insert(b);
    connections[b].insert(a);
  }

  std::cout << count << "\n";
  return 1;
}
