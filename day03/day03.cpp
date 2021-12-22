#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/3

constexpr int make_const() {
  // Helper function to make constexpr int for bitset construction
  return 12;
}
unsigned long part_one() {
  // constexpr std::size_t n = 12;
  constexpr auto n = make_const();
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<unsigned int> v(n);
  unsigned int line_count = std::count_if(
      std::istream_iterator<std::bitset<n>>(fin),
      std::istream_iterator<std::bitset<n>>(), [&v](std::bitset<n> b) {
        for (std::size_t i = 0; i < b.size(); ++i) {
          if (b.test(i)) {
            v[i]++;
          }
        }
        return true;
      });
  std::bitset<n> gamma;
  for (std::size_t i = 0; i < n; i++) {
    gamma[i] = (v[i] >= line_count / 2) ? 1 : 0;
  }
  return gamma.to_ulong() * gamma.flip().to_ulong();
}

unsigned long part_two() {
  constexpr auto n = make_const();
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::vector<std::bitset<n>> v;
  std::move(std::istream_iterator<std::bitset<n>>(fin),
            std::istream_iterator<std::bitset<n>>(), std::back_inserter(v));
  std::function<std::bitset<n>(std::vector<std::bitset<n>>::iterator,
                               std::vector<std::bitset<n>>::iterator,
                               std::size_t, bool)>
      calc_rate = [&calc_rate](auto begin, auto end, auto pos, bool O2) {
        if (end - begin == 1 || pos == -1) {
          return *begin;
        }
        auto split =
            std::partition(begin, end, [&pos](auto i) { return i[pos] == 1; });
        if (O2) {
          if (std::distance(begin, split) >= std::distance(split, end))
            return calc_rate(begin, split, --pos, O2);
          return calc_rate(split, end, --pos, O2);
        }
        if (std::distance(begin, split) < std::distance(split, end))
          return calc_rate(begin, split, --pos, O2);
        return calc_rate(split, end, --pos, O2);
      };
  auto O2_rate = calc_rate(v.begin(), v.end(), n - 1, true);
  auto CO2_rate = calc_rate(v.begin(), v.end(), n - 1, false);
  return O2_rate.to_ulong() * CO2_rate.to_ulong();
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
