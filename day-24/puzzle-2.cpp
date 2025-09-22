#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::string line{};
  while (std::getline(std::cin, line) && !line.empty()) {}

  std::unordered_map<std::string, std::string> wires{};
  while (std::getline(std::cin, line)) {
    auto pos = line.find('-');
    const auto inputs = line.substr(0, pos - 1);
    const auto output = line.substr(pos + 3);
    wires.emplace(inputs, output);
  }

  std::vector<std::string> wrongWires{};

  auto xorIt = wires.find("x00 XOR y00");
  assert(xorIt != wires.end());

  if (xorIt->second != "z00") {
    wrongWires.push_back(xorIt->second);
  }

  auto andIt = wires.find("x00 AND y00");
  assert(andIt != wires.end());

  if (!wrongWires.empty()) {
    std::cout << wrongWires.front();
    for (std::size_t i{1}; i < wrongWires.size(); ++i) {
      std::cout << "," << wrongWires[i];
    }
    std::cout << "\n";
  }

  return 0;
}
