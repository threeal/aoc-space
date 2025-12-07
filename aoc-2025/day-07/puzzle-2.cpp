#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::stack<std::string> lines{};
  std::string line{};
  while (std::getline(std::cin, line)) lines.push(line);

  std::vector<long long> timelines(lines.top().size(), 1);
  while (lines.size() > 1) {
    for (std::size_t i{0}; i < lines.top().size(); ++i) {
      if (lines.top()[i] == '^') {
        timelines[i] = timelines[i - 1] + timelines[i + 1];
      }
    }
    lines.pop();
  }

  long long total{0};
  for (std::size_t i{0}; i < lines.top().size(); ++i) {
    if (lines.top()[i] == 'S') total += timelines[i];
  }

  std::cout << total << '\n';

  return 0;
}
