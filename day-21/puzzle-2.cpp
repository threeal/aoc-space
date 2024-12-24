#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

std::unordered_map<char, std::tuple<std::size_t, std::size_t>> posOf{};
const std::vector<std::vector<char>> charOf{
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
    {' ', '0', 'A'},
    {'<', 'v', '>'}};

int main() {
  std::size_t complexities{0};

  for (std::size_t y{0}; y < charOf.size(); ++y) {
    for (std::size_t x{0}; x < charOf[y].size(); ++x) {
      posOf.emplace(
          charOf[y][x], std::tuple<std::size_t, std::size_t>{y, x});
    }
  }

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t num{0};
    for (std::size_t i{0}; line[i] != 'A'; ++i) {
      num = num * 10 + line[i] - '0';
    }

    std::queue<std::tuple<char, std::string, std::string>> inputs{}, outputs{};
    inputs.push({'A', line, ""});

    for (std::size_t i{0}; i < 3; ++i) {
      while (!inputs.empty()) {
        const auto [pos, in, out] = inputs.front();
        inputs.pop();

        const auto [sy, sx] = posOf[pos];
        const auto [ty, tx] = posOf[in.front()];

        if (sy == ty && sx == tx) {
          if (in.size() > 1) {
            inputs.push({in[0], in.substr(1), out + "A"});
          } else {
            outputs.push({'A', out + "A", ""});
          }
        } else {
          if (sx != tx && charOf[sy][tx] != ' ') {
            if (sx < tx) {
              inputs.push({charOf[sy][tx], in, out + std::string(tx - sx, '>')});
            } else {
              inputs.push({charOf[sy][tx], in, out + std::string(sx - tx, '<')});
            }
          }

          if (sy != ty && charOf[ty][sx] != ' ') {
            if (sy < ty) {
              inputs.push({charOf[ty][sx], in, out + std::string(ty - sy, 'v')});
            } else {
              inputs.push({charOf[ty][sx], in, out + std::string(sy - ty, '0')});
            }
          }
        }
      }

      std::swap(inputs, outputs);
    }

    std::size_t shortest{std::numeric_limits<std::size_t>::max()};
    while (!inputs.empty()) {
      const auto [pos, in, out] = inputs.front();
      if (in.size() < shortest) shortest = in.size();
      inputs.pop();
    }
    complexities += num * shortest;
  }

  std::cout << complexities << "\n";
  return 1;
}
