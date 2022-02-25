/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.94%)
 * Likes:    1349
 * Dislikes: 216
 * Total Accepted:    263.3K
 * Total Submissions: 775.8K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 *
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }

    auto m = obstacleGrid.size();
    auto n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
      return 0;  // 起点或终点为障碍
    }

    vector<vector<long>> dp(m, vector<long>(n, 0));

    // 初始化第 0 列、第 0 行，遇到障碍则之后都为 0
    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0] == 1) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i] == 1) {
        break;
      }
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};
// @lc code=end
