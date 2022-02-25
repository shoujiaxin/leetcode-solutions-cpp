/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.29%)
 * Likes:    928
 * Dislikes: 1560
 * Total Accepted:    432.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    long root = x;

    // Newton's method
    // https://en.wikipedia.org/wiki/Newton%27s_method
    while (root * root > x) {
      root = (root * root + x) / (2 * root);
    }

    return root;
  }
};
// @lc code=end
