/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.71%)
 * Likes:    826
 * Dislikes: 204
 * Total Accepted:    97.7K
 * Total Submissions: 197.9K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 *
 * Example 1:
 *
 *
 *
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 1);  // dp[i] 表示整数 i 的最大乘积

    for (auto i = 2; i <= n; ++i) {
      for (auto j = 1; j < i; ++j) {
        // 1. 分解为 i - j 和 j，且 i - j 部分继续分解
        // 2. 分解为 i - j 和 j，但 i - j 部分不再分解
        // 3. 不分解
        dp[i] = max({dp[i - j] * j, (i - j) * j, dp[i]});
      }
    }

    return dp[n];
  }
};
// @lc code=end
