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
    // n = 2 => 1 x 1 = 1
    // n = 3 => 1 x 2 = 2
    if (n <= 3) {
      return n - 1;
    }

    // 贪心算法：优先分解为 3、再分解为 2、最后分解为 1
    int a = n / 3;
    int b = n % 3;

    switch (b) {
      case 0:
        // 被 3 整除，全部分解为 3
        return pow(3, a);
      case 1:
        // 被 3 除余 1，将一个 3 分解为 2 x 2
        return pow(3, a - 1) * 4;
      default:
        // 被 3 除余 2
        return pow(3, a) * 2;
    }
  }
};
// @lc code=end
