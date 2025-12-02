#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Connections =
    std::unordered_map<std::string, std::unordered_set<std::string>>;

static std::string find(
    const Connections& connections, std::vector<std::string>& computers);

int main() {
  Connections connections{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    const auto delimiter = line.find('-');
    const auto a = line.substr(0, delimiter);
    const auto b = line.substr(delimiter + 1);

    connections[a].insert(b);
    connections[b].insert(a);
  }

  std::string longestPassword{""};
  std::vector<std::string> computers{};
  for (const auto& [computer, _] : connections) {
    computers.push_back(computer);
    const std::string password{find(connections, computers)};
    if (password.size() > longestPassword.size()) longestPassword = password;
    computers.pop_back();
  }

  std::cout << longestPassword << "\n";

  return 0;
}

static std::string find(
    const Connections& connections, std::vector<std::string>& computers) {
  std::string longestPassword{computers[0]};
  for (std::size_t i{1}; i < computers.size(); ++i) {
    longestPassword += "," + computers[i];
  }

  const auto it = connections.find(computers.back());
  if (it != connections.end()) {
    for (const std::string& nextComputer : it->second) {
      if (nextComputer > computers.back()) {
        std::size_t i{0};
        while (i < computers.size()) {
          const auto it = connections.find(computers[i]);
          if (it == connections.end()) break;
          if (!it->second.contains(nextComputer)) break;
          ++i;
        }

        if (i == computers.size()) {
          computers.push_back(nextComputer);
          const std::string& password(find(connections, computers));
          if (password.size() > longestPassword.size()) {
            longestPassword = password;
          }
          computers.pop_back();
        }
      }
    }
  }

  return longestPassword;
}
