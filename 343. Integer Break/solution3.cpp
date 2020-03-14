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
    array<int, 3> dp{0, 1, 1};

    for (auto i = 3; i <= n; ++i) {
      // 将 i 分解为 i - x 和 x
      // 若 i - x 不再分解，则乘积为 (i - x) * x
      // 若 i - x 继续分解，则乘积为 dp[i - x] * x
      auto breakByOne = 1 * max(dp[(i - 1) % 3], i - 1);
      auto breakByTwo = 2 * max(dp[(i - 2) % 3], i - 2);
      auto breakByThree = 3 * max(dp[(i - 3) % 3], i - 3);
      dp[i % 3] = max({breakByOne, breakByTwo, breakByThree});
    }

    return dp[n % 3];
  }
};
// @lc code=end
