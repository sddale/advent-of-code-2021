#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/14

auto create_polymer(const int steps) -> const long {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s, hold;
  getline(fin, s);
  std::unordered_map<std::string, long> pairs;
  for (long i = 0; i < s.size() - 1; ++i) {
    ++pairs[s.substr(i, 2)];
  }
  getline(fin, s);  // trash blank line
  std::unordered_map<std::string, char> rules;
  while (getline(fin, s, ' ')) {
    getline(fin, hold, ' ');  // trash '->'
    getline(fin, hold);
    rules.insert({std::move(s), std::move(hold[0])});
  }
  for (int i = 0; i < steps; ++i) {
    std::unordered_map<std::string, long> next;
    for (const auto& [k, v] : pairs) {
      char c = rules[k];
      next[k.substr(0, 1) + c] += v;
      next[c + k.substr(1)] += v;
    }
    pairs = std::move(next);
  }
  std::unordered_map<char, long> counts;
  for (const auto& [k, v] : pairs) {
    counts[k[0]] += v;
    counts[k[1]] += v;
  }
  std::set<long> order;
  for (const auto& [_, v] : counts) {
    order.insert(std::move(v));
  }

  return (*std::prev(order.end(), 1) - *order.begin() + 1) / 2;
}
auto part_one() -> const long { return create_polymer(10); }
auto part_two() -> const long { return create_polymer(40); }
int main() {
  std::cout << "Part one:\n" << part_one() << std::endl;
  std::cout << "Part two:\n" << part_two() << std::endl;
  return 0;
}