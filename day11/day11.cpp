#include "aoc.h"

// Prompt: https://adventofcode.com/2021/day/11
constexpr int line_length() { return 10; }
struct octopus {
  octopus(int e) : energy{e} {};
  static int total_flashes;
  int energy;
  std::vector<octopus*> neighbors;
  bool flashing() { return (energy > 9); }
  void finish_step() {
    if (flashing()) {
      energy = 0;
    }
  }
  void flash() {
    total_flashes++;
    for (octopus* n : neighbors) {
      ++(*n);
    }
  }
  constexpr inline octopus& operator++() {
    if (not flashing()) {
      this->energy++;
      if (energy > 9) {
        flash();
      }
    }
    return *this;
  }
};
int octopus::total_flashes;
auto part_one() -> const int {
  constexpr int n_days = 100;
  constexpr int cols = line_length();
  std::ifstream fin("../input.txt");
  std::vector<int> v;
  std::vector<std::vector<octopus>> octopi;
  std::move(std::istream_iterator<uint8_t>(fin),
            std::istream_iterator<uint8_t>(), std::back_inserter(v));
  for (int i = 0; i < ceil(v.size() / cols); ++i) {
    std::vector<octopus> row;
    for (int j = 0; j < cols; ++j) {
      row.push_back({std::move(v[i * cols + j]) - 48});
    }
    octopi.push_back(std::move(row));
  }
  const int rows = octopi.size();
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      std::vector<octopus*> neighbors;
      if (r > 0) {
        neighbors.push_back(&octopi[r - 1][c]);
        if (c > 0) {
          neighbors.push_back(&octopi[r - 1][c - 1]);
        }
        if (c < cols - 1) {
          neighbors.push_back(&octopi[r - 1][c + 1]);
        }
      }
      if (c > 0) {
        neighbors.push_back(&octopi[r][c - 1]);
      }
      if (c < cols - 1) {
        neighbors.push_back(&octopi[r][c + 1]);
      }
      if (r < rows - 1) {
        neighbors.push_back(&octopi[r + 1][c]);
        if (c > 0) {
          neighbors.push_back(&octopi[r + 1][c - 1]);
        }
        if (c < cols - 1) {
          neighbors.push_back(&octopi[r + 1][c + 1]);
        }
      }
      octopi[r][c].neighbors = std::move(neighbors);
    }
  }
  for (int i = 0; i < n_days; ++i) {
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        ++octopi[r][c];
      }
    }
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        octopi[r][c].finish_step();
      }
    }
  }
  return octopus::total_flashes;
}

auto part_two() -> const int {
  constexpr int cols = line_length();
  std::ifstream fin("../input.txt");
  std::vector<int> v;
  std::vector<std::vector<octopus>> octopi;
  std::move(std::istream_iterator<uint8_t>(fin),
            std::istream_iterator<uint8_t>(), std::back_inserter(v));
  for (int i = 0; i < ceil(v.size() / cols); ++i) {
    std::vector<octopus> row;
    for (int j = 0; j < cols; ++j) {
      row.push_back({std::move(v[i * cols + j]) - 48});
    }
    octopi.push_back(std::move(row));
  }
  const int rows = octopi.size();
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      std::vector<octopus*> neighbors;
      if (r > 0) {
        neighbors.push_back(&octopi[r - 1][c]);
        if (c > 0) {
          neighbors.push_back(&octopi[r - 1][c - 1]);
        }
        if (c < cols - 1) {
          neighbors.push_back(&octopi[r - 1][c + 1]);
        }
      }
      if (c > 0) {
        neighbors.push_back(&octopi[r][c - 1]);
      }
      if (c < cols - 1) {
        neighbors.push_back(&octopi[r][c + 1]);
      }
      if (r < rows - 1) {
        neighbors.push_back(&octopi[r + 1][c]);
        if (c > 0) {
          neighbors.push_back(&octopi[r + 1][c - 1]);
        }
        if (c < cols - 1) {
          neighbors.push_back(&octopi[r + 1][c + 1]);
        }
      }
      octopi[r][c].neighbors = std::move(neighbors);
    }
  }
  for (int step = 1;; ++step) {
    bool all_flashing = true;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        ++octopi[r][c];
      }
    }
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (not octopi[r][c].flashing()) {
          all_flashing = false;
        }
        octopi[r][c].finish_step();
      }
    }
    if (all_flashing) {
      return step;
    }
  }
  return -1;
}

int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
