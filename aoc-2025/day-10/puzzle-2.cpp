#include <z3++.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int sum{0};
  std::string line{};
  while (std::getline(std::cin, line)) {
    std::size_t i{1};
    while (line[i] != ']') ++i;

    std::vector<std::vector<int>> buttons{};

    i += 2;
    while (line[i] != '{') {
      buttons.push_back({});
      int num{0};

      ++i;
      while (line[i] != ')') {
        if (line[i] == ',') {
          buttons.back().push_back(num);
          num = 0;
        } else {
          num = num * 10 + line[i] - '0';
        }
        ++i;
      }

      buttons.back().push_back(num);
      i += 2;
    }

    std::vector<int> joltages{};
    int num{0};

    ++i;
    while (line[i] != '}') {
      if (line[i] == ',') {
        joltages.push_back(num);
        num = 0;
      } else {
        num = num * 10 + line[i] - '0';
      }
      ++i;
    }

    joltages.push_back(num);

    z3::context ctx{};
    z3::optimize op(ctx);

    std::vector<z3::expr> exprs{};
    for (std::size_t i{0}; i < joltages.size(); ++i) {
      exprs.push_back(ctx.int_val(0));
    }

    std::vector<z3::expr> vars{};
    z3::expr varsTotal{ctx.int_val(0)};
    for (std::size_t i{0}; i < buttons.size(); ++i) {
      z3::expr var{ctx.int_const(std::string(1, 'a' + i).c_str())};
      op.add(var >= 0);

      vars.push_back(var);
      varsTotal = varsTotal + var;

      for (const int num : buttons[i]) {
        exprs[num] = exprs[num] + var;
      }
    }

    for (std::size_t i{0}; i < joltages.size(); ++i) {
      op.add(exprs[i] == joltages[i]);
    }

    op.minimize(varsTotal);
    if (op.check() != z3::sat) {
      return 1;
    }

    const z3::model m{op.get_model()};

    int count{0};
    for (auto& var : vars) {
      count += m.get_const_interp(var.decl()).get_numeral_int();
    }

    sum += count;
  }

  std::cout << sum << "\n";

  return 0;
}
