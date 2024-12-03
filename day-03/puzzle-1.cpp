#include <iostream>

int main() {
  int sum{0};

  char ch{};
  while (std::cin.get(ch)) {
    if (ch != 'm') continue;

    if (!std::cin.get(ch)) break;
    if (ch != 'u') continue;

    if (!std::cin.get(ch)) break;
    if (ch != 'l') continue;

    if (!std::cin.get(ch)) break;
    if (ch != '(') continue;

    int a{0};
    if (!std::cin.get(ch)) break;
    if (ch >= '0' && ch <= '9') {
      a += ch - '0';
      if (!std::cin.get(ch)) break;
      if (ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        if (!std::cin.get(ch)) break;
        if (ch >= '0' && ch <= '9') {
          a = a * 10 + ch - '0';
          if (!std::cin.get(ch)) break;
          if (ch != ',') continue;
        } else if (ch != ',') {
          continue;
        }
      } else if (ch != ',') {
        continue;
      }
    } else {
      continue;
    }

    int b{0};
    if (!std::cin.get(ch)) break;
    if (ch >= '0' && ch <= '9') {
      b += ch - '0';
      if (!std::cin.get(ch)) break;
      if (ch >= '0' && ch <= '9') {
        b = b * 10 + ch - '0';
        if (!std::cin.get(ch)) break;
        if (ch >= '0' && ch <= '9') {
          b = b * 10 + ch - '0';
          if (!std::cin.get(ch)) break;
          if (ch != ')') continue;
        } else if (ch != ')') {
          continue;
        }
      } else if (ch != ')') {
        continue;
      }
    } else {
      continue;
    }

    sum += a * b;
  }

  std::cout << sum << "\n";
  return 0;
}
