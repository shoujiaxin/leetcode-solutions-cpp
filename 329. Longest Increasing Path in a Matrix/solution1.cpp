/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (43.14%)
 * Likes:    1974
 * Dislikes: 37
 * Total Accepted:    149.5K
 * Total Submissions: 345.3K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return 0;
    }

    rows = matrix.size();
    columns = matrix.front().size();

    auto memo = vector<vector<int>>(rows, vector<int>(columns, 0));
    auto res = 0;

    for (auto i = 0; i < rows; ++i) {
      for (auto j = 0; j < columns; ++j) {
        res = max(res, dfs(matrix, i, j, memo));
      }
    }

    return res;
  }

 private:
  int rows;
  int columns;
  const vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  int dfs(const vector<vector<int>>& matrix, int x, int y,
          vector<vector<int>>& memo) {
    if (memo[x][y] != 0) {
      return memo[x][y];
    }

    ++memo[x][y];

    for (const auto& dir : directions) {
      auto newX = x + dir.first;
      auto newY = y + dir.second;

      if (newX >= 0 && newX < rows && newY >= 0 && newY < columns &&
          matrix[newX][newY] > matrix[x][y]) {
        memo[x][y] = max(memo[x][y], dfs(matrix, newX, newY, memo) + 1);
      }
    }

    return memo[x][y];
  }
};
// @lc code=end
