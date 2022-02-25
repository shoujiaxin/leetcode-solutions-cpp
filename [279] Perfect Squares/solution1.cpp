/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    2226
 * Dislikes: 170
 * Total Accepted:    251.7K
 * Total Submissions: 561.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    // dp[i] 表示和为 i 的完全平方数的个数
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      // j * j <= i 一定要带等号
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
};
// @lc code=end
