#include <iostream>
#include <string>

int main() {
  std::string line{};
  std::getline(std::cin, line);

  long long sum{0};
  long long pos{0};
  long long left_id{0};
  long long right_id = (line.size() - 1) / 2;

  std::size_t left{0};
  std::size_t right{line.size() - 1};

  while (left < right) {
    for (char c{line[left]}; c > '0'; --c, ++pos) {
      sum += pos * left_id;
    }

    ++left;
    ++left_id;

    for (char c{line[left]}; c > '0'; --c, ++pos) {
      while (left < right && line[right] <= '0') {
        right -= 2;
        --right_id;
      }
      if (left >= right) break;
      sum += pos * right_id;
      --line[right];
    }

    ++left;
  }

  for (char c{line[left]}; c > '0'; --c, ++pos) {
    sum += pos * left_id;
  }

  std::cout << sum << "\n";
  return 0;
}
