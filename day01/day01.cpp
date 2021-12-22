#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/1

int part_one() {
  std::ifstream fin("../input1.txt");
  std::istream_iterator<int> fit(fin);
  std::vector<int> v;
  std::move(fit, std::istream_iterator<int>(), std::back_inserter(v));
  return std::inner_product(std::next(v.begin(), 1), v.end(), v.begin(), 0,
                            std::plus<>(), std::greater<>());
}
int part_two() {
  std::ifstream fin("../input1.txt");
  std::istream_iterator<int> fit(fin);
  std::vector<int> v;
  std::move(fit, std::istream_iterator<int>(), std::back_inserter(v));
  return std::inner_product(std::next(v.begin(), 3), v.end(), v.begin(), 0,
                            std::plus<>(), std::greater<>());
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
