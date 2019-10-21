/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.51%)
 * Likes:    2533
 * Dislikes: 3947
 * Total Accepted:    838.1K
 * Total Submissions: 3.3M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */

// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    long int number = 0;

    while (x != 0) {
      number *= 10;
      number += x % 10;
      x /= 10;

      //   if (number < -2147483648 || number >= 2147483648) {
      //     return 0;  // 2^31 = 2147483648
      //   }
      if (static_cast<int>(number) != number) {
        return 0;
      }
    }

    return number;
  }
};
// @lc code=end
