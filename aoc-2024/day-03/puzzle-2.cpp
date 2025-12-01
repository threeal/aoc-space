#include <iostream>

int main() {
  bool enabled{true};
  int sum{0};

  char ch{};
  if (std::cin.get(ch)) {
    while (true) {
      if (enabled) {
        if (ch == 'd') {
          if (!std::cin.get(ch)) break;
          if (ch != 'o') continue;

          if (!std::cin.get(ch)) break;
          if (ch != 'n') continue;

          if (!std::cin.get(ch)) break;
          if (ch != '\'') continue;

          if (!std::cin.get(ch)) break;
          if (ch != 't') continue;

          if (!std::cin.get(ch)) break;
          if (ch != '(') continue;

          if (!std::cin.get(ch)) break;
          if (ch != ')') continue;

          enabled = false;
        } else if (ch == 'm') {
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
      } else if (ch == 'd') {
        if (!std::cin.get(ch)) break;
        if (ch != 'o') continue;

        if (!std::cin.get(ch)) break;
        if (ch != '(') continue;

        if (!std::cin.get(ch)) break;
        if (ch != ')') continue;

        enabled = true;
      }

      if (!std::cin.get(ch)) break;
    }
  }

  std::cout << sum << "\n";
  return 0;
}
