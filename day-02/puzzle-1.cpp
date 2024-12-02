#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string line{};

  int count{0};
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);

    int a{}, b{};
    iss >> a >> b;

    if (a < b) {
    repeat_inc:
      if (b - a <= 0 || b - a > 3) continue;
      a = b;
      if (iss >> b) goto repeat_inc;
      ++count;
    } else if (a > b) {
    repeat_dec:
      if (a - b <= 0 || a - b > 3) continue;
      a = b;
      if (iss >> b) goto repeat_dec;
      ++count;
    }
  }

  std::cout << count << "\n";

  return 0;
}
