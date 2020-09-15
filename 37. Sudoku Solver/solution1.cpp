/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (43.01%)
 * Likes:    2032
 * Dislikes: 93
 * Total Accepted:    197.6K
 * Total Submissions: 447.5K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (auto i = 0; i < 9; ++i) {
      for (auto j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          spaces.push_back({i, j});
        } else {
          auto digit = board[i][j] - '1';
          row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
        }
      }
    }

    backtrack(board, 0);
  }

 private:
  array<array<bool, 9>, 9> row{false};
  array<array<bool, 9>, 9> col{false};
  array<array<array<bool, 9>, 3>, 3> box{false};
  bool valid = false;
  vector<pair<int, int>> spaces;

  void backtrack(vector<vector<char>>& board, int pos) {
    if (pos == spaces.size()) {
      valid = true;
      return;
    }

    auto [i, j] = spaces[pos];
    for (auto digit = 0; digit < 9 && !valid; ++digit) {
      if (!row[i][digit] && !col[j][digit] && !box[i / 3][j / 3][digit]) {
        row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
        board[i][j] = digit + '1';

        backtrack(board, pos + 1);

        row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = false;
      }
    }
  }
};
// @lc code=end
