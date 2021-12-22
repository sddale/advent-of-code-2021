#include "../aoc.h"

// Prompt: https://adventofcode.com/2021/day/4

struct square {
  int row = 0, col = 0;
};
class board {
 public:
  bool in_play = true;
  std::unordered_map<int, square> values;    // fast value->location
  std::array<std::array<int, 5>, 5> layout;  // fast location->value
  bool check_win(int ball) {
    called.insert(ball);
    if (values.count(ball) > 0) {
      square curr = values[ball];
      return check_row(curr) or check_col(curr);
    }
    return false;
  }
  int sum_win(int ball) {
    // 2D fold left over values, if unmarked
    int sum = std::accumulate(
        layout.begin(), layout.end(), 0, [this](int sum, const auto& rhs) {
          return std::accumulate(rhs.begin(), rhs.end(), sum,
                                 [this](int sum, const int rhs) {
                                   if (called.count(rhs) == 0) {
                                     sum += rhs;
                                   }
                                   return sum;
                                 });
        });
    return sum * ball;
  }

 private:
  std::unordered_set<int> called;  // Track marked squares by presence
  bool check_col(square s) {
    for (int i = 0; i < 5; ++i) {
      if (called.count(layout[i][s.col]) == 0) {
        return false;
      }
    }
    return true;
  }
  bool check_row(square s) {
    for (int i = 0; i < 5; ++i) {
      if (called.count(layout[s.row][i]) == 0) {
        return false;
      }
    }
    return true;
  }
};
int play_bingo(bool win_first = true) {
  std::ifstream fin("../input.txt");
  assert(fin.is_open());
  std::string s;
  getline(fin, s);
  std::istringstream sin(s);
  std::vector<int> balls;
  while (getline(sin, s, ',')) {
    balls.push_back(stoi(s));
  }
  std::vector<board> bingo;
  int total_boards = 0;
  while (getline(fin, s)) {
    board b;
    total_boards++;
    int n;
    for (int i = 0; i < 25; ++i) {
      fin >> n;
      b.layout[i / 5][i % 5] = n;
      b.values[n] = {.row = i / 5, .col = i % 5};
    }
    bingo.push_back(b);
  }
  for (const auto& x : balls) {
    for (board& b : bingo) {
      if (b.in_play and b.check_win(x)) {
        if (win_first or total_boards == 1) {
          return b.sum_win(x);
        }
        b.in_play = false;
        total_boards--;
      }
    }
  }

  return 0;
}
int part_one() { return play_bingo(); }
int part_two() { return play_bingo(false); }
int main() {
  std::cout << "Part one: " << part_one() << std::endl;
  std::cout << "Part two: " << part_two() << std::endl;
  return 0;
}
