/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (37.04%)
 * Likes:    2721
 * Dislikes: 68
 * Total Accepted:    243.3K
 * Total Submissions: 656.9K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 */

// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }

    auto m = matrix.size();
    auto n = matrix[0].size();

    auto res = 0;

    // dp[i][j] 表示以 matrix[i - 1][j - 1] 为右下角的最大正方形的边长
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto i = 1; i <= m; ++i) {
      for (auto j = 1; j <= n; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
          res = max(res, dp[i][j]);
        }
      }
    }

    return res * res;
  }
};
// @lc code=end
