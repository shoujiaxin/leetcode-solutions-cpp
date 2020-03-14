/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.68%)
 * Likes:    2877
 * Dislikes: 147
 * Total Accepted:    401.8K
 * Total Submissions: 1.2M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 *
 * Constraints:
 *
 *
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (auto i = 0; i < board.size(); ++i) {
      for (auto j = 0; j < board[0].size(); ++j) {
        // 以矩阵中每个元素为起点进行深度优先遍历
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }

 private:
  /// 深度优先遍历矩阵
  /// @param board 矩阵
  /// @param word 给定单词
  /// @param x 当前矩阵元素行坐标
  /// @param y 当前矩阵元素列坐标
  /// @param i 当前搜索到字符的索引
  bool dfs(vector<vector<char>>& board, const string& word, int x, int y,
           int i) {
    // 超出矩阵范围
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
      return false;
    }

    // 字符不相等
    if (board[x][y] != word[i]) {
      return false;
    }

    // 查找到最后一个字符
    if (i == word.size() - 1) {
      return true;
    }

    auto temp = board[x][y];
    board[x][y] = '*';  // 避免重复访问
    auto res = dfs(board, word, x - 1, y, i + 1) ||
               dfs(board, word, x, y - 1, i + 1) ||
               dfs(board, word, x + 1, y, i + 1) ||
               dfs(board, word, x, y + 1, i + 1);
    board[x][y] = temp;
    return res;
  }
};
// @lc code=end
