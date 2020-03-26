/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    2225
 * Dislikes: 50
 * Total Accepted:    320.3K
 * Total Submissions: 625.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }

    auto m = grid.size();
    auto n = grid[0].size();

    auto dp = grid;

    for (auto i = 1; i < m; ++i) {
      dp[i][0] += dp[i - 1][0];
    }
    for (auto i = 1; i < n; ++i) {
      dp[0][i] += dp[0][i - 1];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
// @lc code=end
