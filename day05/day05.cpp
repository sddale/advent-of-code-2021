#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/5
struct coord {
  coord() {}
  coord(auto x, auto y) : x(x), y(y) {}
  int x;
  int y;
  auto operator<=>(const coord&) const = default;
  friend auto operator<<(std::ostream& os, const coord& c) -> std::ostream& {
    os << '{' << c.x << ", " << c.y << '}' << ' ';
    return os;
  }
  friend auto operator>>(std::istream& is, coord& c) -> std::istream& {
    std::string s;
    getline(is, s, ',');
    c.x = stoi(s);
    is >> c.y;
    return is;
  }
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
  std::string arrow;
  fin >> p1 >> arrow >> p2;
  return {p1, p2};
}
auto draw_lines(bool ignore_diag) -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::unordered_set<coord> drawn;
  std::unordered_set<coord> intersect;
  while (not fin.eof()) {
    auto [p1, p2] = read_line(fin);
    if (ignore_diag && p1.x != p2.x && p1.y != p2.y) {
      continue;
    }
    (drawn.count(p2) > 0) ? intersect.insert(p2) : drawn.insert(p2);
    while (p1 != p2) {
      (drawn.count(p1) > 0) ? intersect.insert(p1) : drawn.insert(p1);
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
  }
  return intersect.size();
}
auto part_one() -> const int { return draw_lines(true); }
auto part_two() -> const int { return draw_lines(false); }
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
