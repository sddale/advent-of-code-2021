#include <algorithm>
#include <cmath>
#include <unordered_map>

#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/10

auto part_one() -> const int {
  std::ifstream fin("../input.txt");
  std::vector<std::string> v;
  std::move(std::istream_iterator<std::string>(fin),
            std::istream_iterator<std::string>(), std::back_inserter(v));
  const std::string lhs = "([{<", rhs = ")]}>";
  const std::unordered_map<char, int> points = {
      {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
  int score = 0;
  for (const auto& s : v) {
    std::stack<char> matcher;
    for (const auto& c : s) {
      const size_t t = rhs.find(c);
      if (t != std::string::npos) {
        if (matcher.empty() or matcher.top() != lhs[t]) {
          score += points.at(rhs[t]);
          break;
        }
        matcher.pop();
      } else {
        matcher.push(c);
      }
    }
  }
  return score;
}
auto part_two() -> const long {
  std::ifstream fin("../input.txt");
  std::vector<std::string> v;
  std::move(std::istream_iterator<std::string>(fin),
            std::istream_iterator<std::string>(), std::back_inserter(v));
  const std::string lhs = "([{<", rhs = ")]}>";
  const std::unordered_map<char, int> points = {
      {'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};
  std::vector<long> scores;
  for (const auto& s : v) {
    bool skip_line = false;
    std::stack<char> matcher;
    for (const auto& c : s) {
      const size_t t = rhs.find(c);
      if (t != std::string::npos) {
        if (matcher.empty() or matcher.top() != lhs[t]) {
          skip_line = true;
          break;
        }
        matcher.pop();
      } else {
        matcher.push(c);
      }
    }
    if (not skip_line and not matcher.empty()) {
      long score = 0;
      while (not matcher.empty()) {
        score = 5 * score + points.at(matcher.top());
        matcher.pop();
      }
      scores.push_back(score);
    }
  }
  const auto m = std::next(scores.begin(), scores.size() / 2);
  std::nth_element(scores.begin(), m, scores.end());
  return *m;
}

int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;  // 1327014
  return 0;
}
