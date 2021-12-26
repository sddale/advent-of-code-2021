#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>

#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/9
constexpr auto line_length() -> int { return 100; }
auto part_one() -> const int {
  constexpr int l = line_length();
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<uint8_t> v;
  std::move(std::istream_iterator<uint8_t>(fin),
            std::istream_iterator<uint8_t>(), std::back_inserter(v));
  auto check_low_pt = [&l, &v](const int i) -> bool {
    if (i % l != 0 and v[i - 1] <= v[i]) {  // Check left
      return false;
    }
    if (i % l != l - 1 and v[i + 1] <= v[i]) {  // Check right
      return false;
    }
    if (i >= l and v[i - l] <= v[i]) {  // Check above
      return false;
    }
    if (i < v.size() - l and v[i + l] <= v[i]) {  // Check below
      return false;
    }
    return true;
  };
  int sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (check_low_pt(i)) {
      sum += v[i] - 47;  // char '0' is 48, prompt says add 1 => -47
    }
  }
  return sum;
}
auto part_two() -> const int {
  constexpr int l = line_length();
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<uint8_t> v;
  std::move(std::istream_iterator<uint8_t>(fin),
            std::istream_iterator<uint8_t>(), std::back_inserter(v));
  auto find_basin_bfs = [&l, &v](const int i) -> int {
    int size = 0;
    std::queue<int> q;
    q.push(i);
    while (not q.empty()) {
      const int t = q.front();
      q.pop();
      if (v[t] != '9') {
        v[t] = '9';
        size++;
        if (t % l != 0) {  // Check left
          q.push(t - 1);
        }
        if (t % l != l - 1) {  // Check right
          q.push(t + 1);
        }
        if (t >= l) {  // Check above
          q.push(t - l);
        }
        if (t < v.size() - l) {  // Check below
          q.push(t + l);
        }
      }
    }
    return size;
  };
  std::array<int, 3> max = {0, 0, 0};
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] != '9') {
      int n = find_basin_bfs(i);
      if (n > max[2]) {
        std::exchange(max[0], std::exchange(max[1], std::exchange(max[2], n)));
      } else if (n > max[1]) {
        std::exchange(max[0], std::exchange(max[1], n));
      } else if (n > max[0]) {
        std::exchange(max[0], n);
      }
    }
  }
  return std::accumulate(max.begin(), max.end(), 1, std::multiplies<>());
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;  // 1327014
  return 0;
}
