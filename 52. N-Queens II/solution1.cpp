/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (56.07%)
 * Likes:    422
 * Dislikes: 138
 * Total Accepted:    125.2K
 * Total Submissions: 222.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 *
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);

    return res;
  }

 private:
  int res;

  // 能否在 board[row][col] 放置皇后
  bool isValid(const vector<string> &board, int row, int col) {
    auto n = board.size();

    // 列
    for (auto i = 0; i < n; ++i) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }

    // 主对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    // 副对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }

  void backtrack(vector<string> &board, int row) {
    if (row == board.size()) {
      ++res;
      return;
    }

    for (auto col = 0; col < board.size(); ++col) {
      if (!isValid(board, row, col)) {
        continue;
      }

      board[row][col] = 'Q';
      backtrack(board, row + 1);
      board[row][col] = '.';
    }
  }
};
// @lc code=end
