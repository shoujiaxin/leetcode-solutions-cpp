/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (44.41%)
 * Likes:    1571
 * Dislikes: 65
 * Total Accepted:    187.4K
 * Total Submissions: 420.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 *
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);

    return res;
  }

 private:
  vector<vector<string>> res;

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
      res.push_back(board);
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
