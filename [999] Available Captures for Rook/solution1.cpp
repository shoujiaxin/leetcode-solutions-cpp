/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 *
 * https://leetcode.com/problems/available-captures-for-rook/description/
 *
 * algorithms
 * Easy (66.05%)
 * Likes:    162
 * Dislikes: 338
 * Total Accepted:    24.5K
 * Total Submissions: 37K
 * Testcase Example:
 * '[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]'
 *
 * On an 8 x 8 chessboard, there is one white rook.  There also may be empty
 * squares, white bishops, and black pawns.  These are given as characters 'R',
 * '.', 'B', and 'p' respectively. Uppercase characters represent white pieces,
 * and lowercase characters represent black pieces.
 *
 * The rook moves as in the rules of Chess: it chooses one of four cardinal
 * directions (north, east, west, and south), then moves in that direction
 * until it chooses to stop, reaches the edge of the board, or captures an
 * opposite colored pawn by moving to the same square it occupies.  Also, rooks
 * cannot move into the same square as other friendly bishops.
 *
 * Return the number of pawns the rook can capture in one move.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation:
 * In this example the rook is able to capture all the pawns.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input:
 * [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 0
 * Explanation:
 * Bishops are blocking the rook to capture any pawn.
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input:
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation:
 * The rook can capture the pawns at positions b5, d6 and f5.
 *
 *
 *
 *
 * Note:
 *
 *
 * board.length == board[i].length == 8
 * board[i][j] is either 'R', '.', 'B', or 'p'
 * There is exactly one cell with board[i][j] == 'R'
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          dfs(board, i, j, -1, 0);
          dfs(board, i, j, 1, 0);
          dfs(board, i, j, 0, 1);
          dfs(board, i, j, 0, -1);
        }
      }
    }

    return res;
  }

 private:
  int res = 0;

  void dfs(const vector<vector<char>>& board, int x, int y, int dx, int dy) {
    if (x < 0 || y < 0 || x > 7 || y > 7 || board[x][y] == 'B') {
      return;
    }

    if (board[x][y] == 'p') {
      ++res;
      return;
    }

    dfs(board, x + dx, y + dy, dx, dy);
  }
};
// @lc code=end
