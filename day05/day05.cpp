#include <algorithm>
#include <array>
#include <bitset>
#include <compare>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

// Prompt: https://adventofcode.com/2021/day/5
struct coord {
  coord() {}
  coord(auto x, auto y) : x(x), y(y) {}
  int x;
  int y;
  auto operator<=>(const coord&) const = default;
};
template <>
struct std::hash<coord> {
  auto operator()(coord const& s) const -> std::size_t {
    auto h1 = std::hash<int>{}(s.x);
    auto h2 = std::hash<int>{}(s.y);
    return h1 ^ (h2 << 1);
  }
};
auto read_line(std::ifstream& fin) -> std::tuple<coord, coord> {
  coord p1, p2;
  std::string s, arrow;
  getline(fin, s, ',');
  p1.x = stoi(s);
  fin >> p1.y >> arrow;
  getline(fin, s, ',');
  p2.x = stoi(s);
  fin >> p2.y;
  return {p1, p2};
}
auto draw_lines(bool ignore_diag) -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::unordered_map<coord, int> m;
  while (not fin.eof()) {
    auto [p1, p2] = read_line(fin);
    if (ignore_diag and (p1.x != p2.x and p1.y != p2.y)) {
      continue;
    }
    while (p1 != p2) {
      m[p1]++;
      if (p1.x < p2.x) {
        p1.x++;
      } else if (p2.x < p1.x) {
        p1.x--;
      }
      if (p1.y < p2.y) {
        p1.y++;
      } else if (p2.y < p1.y) {
        p1.y--;
      }
    }
    m[p1]++;
  }
  return std::count_if(m.begin(), m.end(),
                       [&m](auto x) { return x.second > 1; });
}
auto part_one() -> const int { return draw_lines(true); }
auto part_two() -> const int { return draw_lines(false); }
int main() {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
