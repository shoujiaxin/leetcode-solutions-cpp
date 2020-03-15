/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (29.12%)
 * Likes:    1203
 * Dislikes: 2694
 * Total Accepted:    415.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 *
 * Example 1:
 *
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 * Note:
 *
 *
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 0 || x == 1) {
      return x;
    }

    // 平方求幂/快速幂
    decltype(x) r = 1;
    auto i = n;
    while (i) {
      if (i & 1) {
        r *= x;
      }

      x *= x;
      i /= 2;
    }

    return (n < 0) ? 1 / r : r;
  }
};
// @lc code=end
