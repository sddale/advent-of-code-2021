#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/6

auto count_fish(const auto days) -> const long {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  std::array<long, 9> fish{0, 0, 0, 0, 0,
                           0, 0, 0, 0};  // organize fish by timer
  while (getline(fin, s, ',')) {
    fish[stoi(s)]++;
  }
  for (auto i = days; i > 0; --i) {
    long fish_0 = std::move(fish[0]);
    fish[7] += fish_0;
    std::shift_left(fish.begin(), fish.end(), 1);
    fish[8] = std::move(fish_0);
  }
  return std::accumulate(fish.begin(), fish.end(), 0L);
}
auto part_one() -> const long { return count_fish(80); }
auto part_two() -> const long { return count_fish(256); }
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
