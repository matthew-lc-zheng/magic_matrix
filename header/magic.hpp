#include <iomanip>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

class magic_matrix {
  vector<vector<int>> table;
  int level, start;

public:
  magic_matrix(int level, int start) : level(level), start(start) {
    if (level < 3) {
      cerr << "Pease set a value greater than 2 for level\n";
    }
    if (start < 1) {
      cerr << "Please set positive value for start.\n";
    }

    table = vector(level, vector(level, 0));

    if (level & 1) {
      int number = start;
      int x = level - 1, y = level / 2;
      while (number < (start + level * level)) {
        table[x][y] = number++;
        if (x == level - 1 && y == level - 1 ||
            x < level - 1 && y < level - 1 && table[x + 1][y + 1]) {
          --x;
        } else if (x == level - 1) {
          x = 0;
          ++y;
        } else if (y == level - 1) {
          ++x;
          y = 0;
        } else {
          ++x;
          ++y;
        }
      }
    } else {
      /// for magic matrix in level 4.
      //      for (auto i = 0; i < table.size(); ++i)
      //        for (auto j = 0; j < table[0].size(); ++j)
      //          table[i][j] = i * level + j + start;

      //      for (auto i = 0; i < level / 2; ++i) {
      //        swap(table[i][i], table[level - i - 1][level - i - 1]);
      //        swap(table[level - 1 - i][i], table[i][level - i - 1]);
      //      }

      //        to do: level 4*k
      //        to do: level 4*k+2
      cerr << "Even level is not supported temporarily.\n";
    }
  }
  magic_matrix(int level) : magic_matrix(level, 1) {}
  magic_matrix() : magic_matrix(3, 1) {}

  void display() const {
    auto digit = to_string(level * level).length();
    cout << "The magic matrix in level " << level << " , starting from "
         << start << " is:\n";
    for (auto i : table) {
      for (auto j : i)
        cout << setw(digit) << j << " ";
      cout << endl;
    }
  }
  bool varify() const {
    int valid_sum = (2 * start + level * level - 1) * level / 2;
    int s_row = 0, s_col = 0, s_slash = 0, s_bslash = 0;
    for (auto i = 0; i < level; ++i) {
      for (auto j = 0; j < level; ++j) {
        s_row += table[i][j];
        s_col += table[j][i];
        if (i == j)
          s_slash += table[i][j];
        if (i + j == level - 1)
          s_bslash += table[i][j];
      }
      if (s_row != valid_sum || s_col != valid_sum)
        return false;
      s_row = 0;
      s_col = 0;
    }
    return s_slash == valid_sum && s_bslash == valid_sum;
  }
};
