/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.66%)
 * Likes:    1094
 * Dislikes: 1999
 * Total Accepted:    174.3K
 * Total Submissions: 344.3K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 *
 *
 * Example 1:
 *
 *
 * Input: a = 1, b = 2
 * Output: 3
 *
 *
 *
 * Example 2:
 *
 *
 * Input: a = -2, b = 3
 * Output: 1
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int getSum(int a, int b) {
    // a ^ b：无进位相加
    // a & b：每一位的进位
    // a + b：让无进位相加的结果与进位不断的异或， 直到进位为 0
    while (b) {
      auto c = (static_cast<unsigned>(a) & b) << 1;  // 进位
      a = a ^ b;                                     // 无进位的和
      b = c;
    }

    return a;
  }
};
// @lc code=end
