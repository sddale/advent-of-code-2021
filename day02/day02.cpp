#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Prompt: https://adventofcode.com/2021/day/2

unsigned int part_one() {
  std::unordered_map<std::string, int> m;
  std::ifstream fin("input.txt");
  std::string s;
  unsigned int num;
  while (getline(fin, s)) {
    std::istringstream sin(s);
    sin >> s >> num;
    m[s] += num;
  }
  return m["forward"] * (m["down"] - m["up"]);
}
unsigned int part_two() {
  std::unordered_map<std::string, int> m;
  std::ifstream fin("input.txt");
  std::string s;
  unsigned int aim;
  unsigned int num;
  while (getline(fin, s)) {
    std::istringstream sin(s);
    sin >> s >> num;
    if (s == "forward") {
      aim = m["down"] - m["up"];
      m["depth"] += aim * num;
    }
    m[s] += num;
  }
  return m["forward"] * m["depth"];
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
