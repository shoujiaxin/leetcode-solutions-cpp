/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (31.07%)
 * Likes:    268
 * Dislikes: 601
 * Total Accepted:    47.9K
 * Total Submissions: 153.4K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * Example:
 *
 *
 * Input: 13
 * Output: 6
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countDigitOne(int n) {
    if (n < 0) {
      return 0;
    }

    auto res = 0;

    long long digit = 1;  // 位数
    auto high = n / 10;   // 高位
    auto cur = n % 10;    // 当前位
    auto low = 0;         // 低位

    while (high != 0 || cur != 0) {
      if (cur == 0) {
        res += high * digit;
      } else if (cur == 1) {
        res += high * digit + low + 1;
      } else {
        res += (high + 1) * digit;
      }

      low += cur * digit;
      cur = high % 10;
      high /= 10;
      digit *= 10;
    }

    return res;
  }
};
// @lc code=end
