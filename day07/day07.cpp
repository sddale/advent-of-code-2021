#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/7

auto part_one() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  std::vector<int> v;
  while (getline(fin, s, ',')) {
    v.push_back(stoi(s));
  }
  // Median minimizes l1 norm
  auto m = v.begin() + v.size() / 2;
  std::nth_element(v.begin(), m, v.end());
  return std::accumulate(v.begin(), v.end(), 0, [&m](int sum, int val) {
    return sum + abs(val - *m);
  });
}
auto part_two() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  std::vector<int> v;
  while (getline(fin, s, ',')) {
    v.push_back(stoi(s));
  }
  // Need to minimize avg of l1, l2 norms
  // This reduces to fuel @ +/- 0.5 from mean
  int mean = std::accumulate(v.begin(), v.end(), 0) / v.size();
  int mean_fuel =
      std::accumulate(v.begin(), v.end(), 0, [&mean](int sum, int val) {
        int dist = abs(val - mean);
        return sum + dist * (dist + 1) / 2;
      });
  return mean_fuel;
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
