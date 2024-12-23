#include <iostream>
#include <string>

int main() {
  std::string line{};
  while (std::getline(std::cin, line)) {
    const auto delimiter = line.find('-');
    const auto a = line.substr(0, delimiter);
    const auto b = line.substr(delimiter + 1);
    std::cout << a << " " << b << "\n";
  }

  return 1;
}
