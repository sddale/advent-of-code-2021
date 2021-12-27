#include <cassert>
#include <cctype>
#include <fstream>
#include <ios>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/12

auto part_one() -> const int {
  using node_set = std::unordered_set<std::string>;
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s, t;
  std::unordered_map<std::string, node_set> edges;
  while (std::getline(fin, s, '-')) {
    std::getline(fin, t);
    edges[s].insert(t);
    edges[t].insert(s);
  }
  auto is_small = [](std::string s) -> bool { return (std::islower(s[0])); };
  std::function<void(const std::string&, node_set, int&)> dfs =
      [&](const std::string& s, node_set visited, int& count) -> void {
    if (s == "end") {
      count++;
      return;
    }
    if (is_small(s)) {
      visited.insert(s);
    }
    for (auto v : edges[s]) {
      if (visited.count(v) == 0) {
        dfs(v, visited, count);
      }
    }
  };
  int count = 0;
  dfs("start", {}, count);
  return count;
}
auto part_two() -> const int {
  using node_set = std::unordered_set<std::string>;
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s, t;
  std::unordered_map<std::string, node_set> edges;
  while (std::getline(fin, s, '-')) {
    std::getline(fin, t);
    edges[s].insert(t);
    edges[t].insert(s);
  }
  auto is_small = [](std::string s) -> bool { return (std::islower(s[0])); };
  int count = 0;
  std::function<void(const std::string&, node_set, int&, bool)> dfs =
      [&](const std::string& s, node_set visited, int& count,
          bool counted_twice) -> void {
    if (s == "end") {
      count++;
      return;
    }
    if (is_small(s)) {
      visited.insert(s);
    }
    for (auto v : edges[s]) {
      if (visited.count(v) == 0) {
        dfs(v, visited, count, counted_twice);
      } else if (v != "end" and v != "start" and not counted_twice) {
        dfs(v, visited, count, true);
      }
    }
  };
  dfs("start", {}, count, false);
  return count;
}

int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}