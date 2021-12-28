#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/15

struct coord {
  int x, y, val;
  constexpr inline auto operator>(const coord& c) const -> bool {
    return (val > c.val);
  }
};
template <>
struct std::hash<coord> {
  constexpr auto operator()(coord const& s) const -> std::size_t {
    const auto h1 = std::hash<int>{}(s.x);
    const auto h2 = std::hash<int>{}(s.y);
    return h1 ^ (h2 << 1);
  }
};
auto dijkstras(std::vector<std::string>& v) -> const int {
  const int r = v.size(), c = v[0].size();
  std::vector<std::vector<int>> dist(
      r, std::vector<int>(c, std::numeric_limits<int>::max()));
  std::priority_queue<coord, std::vector<coord>, std::greater<>> q;
  q.push({0, 0, 0});
  dist[0][0] = 0;
  const coord goal = {r - 1, c - 1, dist[r - 1][c - 1]};
  while (not q.empty()) {
    const auto min = q.top();
    q.pop();
    const int x = std::move(min.x), y = std::move(min.y);
    if (min.x == goal.x and min.y == goal.y) {
      return min.val;
    }
    auto check_neighbor = [&](const int& x2, const int& y2) {
      const int t = dist[x][y] + v[x2][y2] - 48;
      if (t < dist[x2][y2]) {
        dist[x2][y2] = t;
        q.push({x2, y2, dist[x2][y2]});
      }
    };
    if (x > 0) {
      check_neighbor(x - 1, y);
    }
    if (x < r - 1) {
      check_neighbor(x + 1, y);
    }
    if (y > 0) {
      check_neighbor(x, y - 1);
    }
    if (y < c - 1) {
      check_neighbor(x, y + 1);
    }
  }
  return 0;
}
auto part_one() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<std::string> v;
  std::move(std::istream_iterator<std::string>(fin),
            std::istream_iterator<std::string>(), std::back_inserter(v));
  return dijkstras(v);
}
auto part_two() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<std::string> v;
  std::move(std::istream_iterator<std::string>(fin),
            std::istream_iterator<std::string>(), std::back_inserter(v));
  int r = v.size(), c = v[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < 4 * c; ++j) {
      if (v[i][j] < '9') {
        v[i].push_back(v[i][j] + 1);
      } else {
        v[i].push_back('1');
      }
    }
  }
  for (int i = 0; i < 4 * r; ++i) {
    auto t = v[i];
    for (char& ch : t) {
      (ch < '9') ? ch++ : ch = '1';
    }
    v.push_back(std::move(t));
  }
  return dijkstras(v);
}
using namespace std::literals;
int main() {
  std::cout << "Part one:\n" << part_one() << std::endl;
  std::cout << "Part two:\n" << part_two() << std::endl;
  return 0;
}