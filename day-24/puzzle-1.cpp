#include <iostream>
#include <string>

int main() {
  std::string line{};
  while (std::getline(std::cin, line) && !line.empty()) {
    const auto pos = line.find(':');
    const auto wire = line.substr(0, pos);
    const auto value = line[pos + 2] == '1';
    std::cout << wire << ", " << value << "\n";
  }

  while (std::getline(std::cin, line)) {
    auto pos = line.find(' ');
    const auto a = line.substr(0, pos);

    auto prev = pos + 1;
    pos = line.find(' ', prev);
    const auto op = line.substr(prev, pos - prev);

    prev = pos + 1;
    pos = line.find(' ', prev);
    const auto b = line.substr(prev, pos - prev);

    pos = line.find(' ', pos + 1);
    const auto c = line.substr(pos + 1, line.size() - pos - 1);

    std::cout << a << ", " << op << ", " << b << ", " << c << "\n";
  }

  return 1;
}
