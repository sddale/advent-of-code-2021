#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

unsigned int part_one() {
  std::ifstream fin("input1.txt");
  std::istream_iterator<unsigned int> fit(fin);
  unsigned int prev = INT32_MAX;
  return std::count_if(
      fit, std::istream_iterator<unsigned int>(),
      [&prev](unsigned int i) { return (std::exchange(prev, i) < i); });
}
unsigned int part_two() {
  std::ifstream fin("input2.txt");
  std::istream_iterator<unsigned int> fit(fin);
  unsigned int prevprev = 0, prev = 0, curr = 0, sum = INT32_MAX;
  prevprev = std::exchange(prev, std::exchange(curr, *fit++));
  prevprev = std::exchange(prev, std::exchange(curr, *fit++));
  return std::count_if(fit, std::istream_iterator<unsigned int>(),
                       [&](const unsigned int i) {
                         prevprev = std::exchange(prev, std::exchange(curr, i));
                         return (std::exchange(sum, prevprev + prev + curr) <
                                 prevprev + prev + curr);
                       });
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
