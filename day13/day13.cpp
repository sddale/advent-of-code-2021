#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/13
template <>
struct std::hash<std::pair<int, int>> {
  auto operator()(std::pair<int, int> const& s) const -> std::size_t {
    auto h1 = std::hash<int>{}(s.first);
    auto h2 = std::hash<int>{}(s.second);
    return h1 ^ (h2 << 1);
  }
};
auto part_one() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::unordered_set<std::pair<int, int>> dots;
  std::string s, t;
  while (getline(fin, s)) {
    auto it = s.find(',');
    if (it == std::string::npos) {
      break;
    }
    dots.insert({stoi(s.substr(0, it)), stoi(s.substr(it + 1))});
  }
  getline(fin, s);
  char axis = s[11];
  int line = stoi(s.substr(13));
  std::unordered_set<std::pair<int, int>> folded_dots;
  for (std::pair<int, int> c : dots) {
    int& v = (axis == 'x') ? c.first : c.second;
    if (v > line) {
      v = 2 * line - v;
    }
    folded_dots.insert(std::move(c));
  }
  return folded_dots.size();
}
auto part_two() -> std::string {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::unordered_set<std::pair<int, int>> dots;
  std::string s, t;
  while (getline(fin, s)) {
    auto it = s.find(',');
    if (it == std::string::npos) {
      break;
    }
    dots.insert({stoi(s.substr(0, it)), stoi(s.substr(it + 1))});
  }
  while (getline(fin, s)) {
    char axis = s[11];
    int line = stoi(s.substr(13));
    std::unordered_set<std::pair<int, int>> folded_dots;
    for (std::pair<int, int> c : dots) {
      int& v = (axis == 'x') ? c.first : c.second;
      if (v > line) {
        v = 2 * line - v;
      }
      folded_dots.insert(std::move(c));
    }
    dots = std::move(folded_dots);
  }
  std::string result;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 39; ++j) {
      if (dots.count({j, i}) > 0) {
        result += '#';
      } else {
        result += ' ';
      }
    }
    result += "\n";
  }
  return result;
}

int main() {
  std::cout << "Part one:\n" << part_one() << std::endl;
  std::cout << "Part two:\n" << part_two() << std::endl;
  return 0;
}