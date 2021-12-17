#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//Prompt: https://adventofcode.com/2021/day/1

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
  unsigned int prevprev = *fit++;
  unsigned int prev = *fit++;
  return std::count_if(
      fit, std::istream_iterator<unsigned int>(),
      [&, curr = 0, sum = INT32_MAX](const unsigned int i) mutable -> bool {
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
