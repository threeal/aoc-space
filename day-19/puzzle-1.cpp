#include <iostream>
#include <list>
#include <string>

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

  std::cout << "patterns:\n";
  bool first = true;
  for (const auto& pattern : patterns) {
    std::cout << "- " << pattern << "\n";
  }

  if (!std::getline(std::cin, line)) return 1;

  std::cout << "designs:\n";
  while (std::getline(std::cin, line)) {
    std::cout << "- " << line << "\n";
  }

  return 1;
}
