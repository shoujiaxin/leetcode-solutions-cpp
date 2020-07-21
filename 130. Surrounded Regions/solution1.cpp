/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (27.75%)
 * Likes:    1837
 * Dislikes: 667
 * Total Accepted:    242.3K
 * Total Submissions: 868.6K
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * Example:
 *
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * After running your function, the board should be:
 *
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * Explanation:
 *
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 */

// @lc code=start
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty()) {
      return;
    }

    auto m = board.size();
    auto n = board[0].size();

    auto x = 0;
    auto y = 0;

    // 第一行
    for (; y < n; ++y) {
      if (board[x][y] == 'O') {
        dfs(board, x, y);
      }
    }

    // 最后一列
    for (--y; x < m; ++x) {
      if (board[x][y] == 'O') {
        dfs(board, x, y);
      }
    }

    // 最后一行
    for (--x; y >= 0; --y) {
      if (board[x][y] == 'O') {
        dfs(board, x, y);
      }
    }

    // 第一列
    for (++y; x >= 0; --x) {
      if (board[x][y] == 'O') {
        dfs(board, x, y);
      }
    }

    for (x = 0; x < m; ++x) {
      for (y = 0; y < n; ++y) {
        if (board[x][y] == '-') {
          board[x][y] = 'O';
        } else if (board[x][y] == 'O') {
          board[x][y] = 'X';
        }
      }
    }
  }

 private:
  void dfs(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
        board[x][y] != 'O') {
      return;
    }

    board[x][y] = '-';

    dfs(board, x - 1, y);
    dfs(board, x, y - 1);
    dfs(board, x + 1, y);
    dfs(board, x, y + 1);
  }
};
// @lc code=end
