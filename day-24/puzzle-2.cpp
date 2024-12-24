#include <iostream>
#include <string>
#include <unordered_map>

class Wire {
 public:
  virtual bool output() const = 0;
};

class BoolWire : public Wire {
  const bool value;

 public:
  BoolWire(const bool value) : value(value) {}
  bool output() const override { return value; }
};

class AndWire : public Wire {
  Wire** a;
  Wire** b;

 public:
  AndWire(Wire** a, Wire** b) : a(a), b(b) {}
  bool output() const override { return (*a)->output() && (*b)->output(); }
};

class OrWire : public Wire {
  Wire** a;
  Wire** b;

 public:
  OrWire(Wire** a, Wire** b) : a(a), b(b) {}
  bool output() const override { return (*a)->output() || (*b)->output(); }
};

class XorWire : public Wire {
  Wire** a;
  Wire** b;

 public:
  XorWire(Wire** a, Wire** b) : a(a), b(b) {}
  bool output() const override { return (*a)->output() != (*b)->output(); }
};

int main() {
  std::unordered_map<std::string, Wire*> wires;

  std::string line{};
  while (std::getline(std::cin, line) && !line.empty()) {
    const auto pos = line.find(':');
    const auto name = line.substr(0, pos);
    const auto value = line[pos + 2] == '1';
    wires.emplace(name, new BoolWire(value));
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
    const auto name = line.substr(pos + 1, line.size() - pos - 1);

    if (op == "AND") {
      wires[name] = new AndWire(&(wires[a]), &(wires[b]));
    } else if (op == "OR") {
      wires[name] = new OrWire(&(wires[a]), &(wires[b]));
    } else if (op == "XOR") {
      wires[name] = new XorWire(&(wires[a]), &(wires[b]));
    } else {
      return 1;
    }
  }

  long long num{0}, i{0};
  std::string name{"z00"};
  auto it = wires.find(name);
  while (it != wires.end()) {
    if (it->second->output()) {
      num |= 1l << i;
    }
    ++i;
    name[1] = '0' + i / 10;
    name[2] = '0' + i % 10;
    it = wires.find(name);
  }
  std::cout << num << "\n";

  return 1;
}
