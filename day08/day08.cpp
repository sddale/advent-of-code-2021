#include <numeric>

#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/8

auto part_one() -> const int {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  int count = 0;
  while (not fin.eof()) {
    getline(fin, s, '|');
    for (int i = 0; i < 4; i++) {
      fin >> s;
      if (s.length() == 2 or s.length() == 4 or s.length() == 3 or
          s.length() == 7) {
        count++;
      }
    }
  }
  return count;
}
auto part_two() -> const int {
  // bitsets track on/off for each of the seven display segment
  // hash maps are used to correlate segment config to displayed val
  const std::unordered_map<std::bitset<7>, int> seg_dict = {
      {0B1110111, 0}, {0B0010010, 1}, {0B1011101, 2}, {0B1011011, 3},
      {0B0111010, 4}, {0B1101011, 5}, {0B1101111, 6}, {0B1010010, 7},
      {0B1111111, 8}, {0B1111011, 9}};
  constexpr std::bitset<7> a{0B1000000}, b{0B0100000}, c{0B0010000},
      d{0B0001000}, e{0B0000100}, f{0B0000010}, g{0B0000001};
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  int sum = 0;
  while (getline(fin, s, '|')) {
    std::string one_pattern, four_pattern;
    std::unordered_map<char, int> symbol_count;
    std::istringstream sin(s);
    for (int i = 0; i < 10; ++i) {
      sin >> s;
      if (s.length() == 2) {
        one_pattern = s;
      } else if (s.length() == 4) {
        four_pattern = s;
      }
      for (const char& c : s) {
        if (c != ' ') {
          symbol_count[c]++;
        }
      }
    }
    getline(fin, s, ' ');  // trash '|' delim
    std::unordered_map<char, std::bitset<7> > char_cipher;
    for (const auto& [ch, i] : symbol_count) {
      switch (i) {
        case 4:  // 'e' occurs 4 times
          char_cipher[ch] = e;
          break;
        case 6:  // 'b' occurs 6 times
          char_cipher[ch] = b;
          break;
        case 9:  // 'f' occurs 9 times
          char_cipher[ch] = f;
          break;
        case 8:  // both 'c' & 'a' occur 8 times, use 'one' to decide
          if (one_pattern.find(ch) != std::string::npos) {
            char_cipher[ch] = c;
          } else {
            char_cipher[ch] = a;
          }
          break;
        case 7:  // both 'd' & 'g' occur 7 times, use 'four' to decide
          if (four_pattern.find(ch) != std::string::npos) {
            char_cipher[ch] = d;
          } else {
            char_cipher[ch] = g;
          }
      }
    }
    for (int i = 3; i >= 0; --i) {
      fin >> s;
      std::bitset<7> b;
      for (const char& c : s) {
        b |= char_cipher.at(c);  // OR char bits to find displayed number
      }
      sum += seg_dict.at(b) * pow(10, i);
    }
  }
  return sum;
}
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
