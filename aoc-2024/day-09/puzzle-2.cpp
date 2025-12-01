#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  std::string line{};
  std::getline(std::cin, line);
  if (line.size() % 2 == 0) line.pop_back();

  std::vector<std::size_t> pos(line.size());
  std::priority_queue<std::size_t, std::vector<std::size_t>, std::greater<std::size_t>> queues[10]{};

  line[0] -= '0';
  pos[0] = 0;
  for (std::size_t i{1}; i < line.size(); ++i) {
    line[i] -= '0';
    pos[i] = pos[i - 1] + line[i - 1];
    if (i % 2 == 1 && line[i] > 0) {
      queues[line[i]].push(i);
    }
  }

  std::size_t checksum{0};
  for (std::size_t i{line.size() - 1}; i > 0; i -= 2) {
    std::size_t candidate{i};
    for (char n{line[i]}; n < 10; ++n) {
      if (!queues[n].empty() && pos[queues[n].top()] < pos[candidate]) {
        candidate = queues[n].top();
      }
    }

    if (candidate != i) {
      queues[line[candidate]].pop();
    }

    checksum += (pos[candidate] * 2 + line[i] - 1) * line[i] / 2 * i / 2;

    if (candidate != i) {
      pos[candidate] += line[i];
      line[candidate] -= line[i];
      if (line[candidate] > 0) {
        queues[line[candidate]].push(candidate);
      }
    }
  }

  std::cout << checksum << "\n";
  return 0;
}
