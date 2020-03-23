/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (31.05%)
 * Likes:    315
 * Dislikes: 957
 * Total Accepted:    54.3K
 * Total Submissions: 174.7K
 * Testcase Example:  '3'
 *
 * Find the n^th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 2^31).
 *
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findNthDigit(int n) {
    if (n < 10) {
      return n;  // 个位数
    }

    // 正整数中，m 位数有 9 * pow(10, m - 1) 个
    int m = 1;
    while (n > 9 * pow(10, m - 1) * m) {
      n -= 9 * pow(10, m - 1) * m;
      ++m;
    }  // 此时 n 表示 m 位数字序列中的第 n 个数字

    int r = n % m;  // 该数字在其所属的 m 位数中的位置（0 为个位，1 为最高位）
    int a = (r == 0) ? n / m : n / m + 1;  // 该数字属于第 a 个 m 位数

    int num = pow(10, m - 1) + a - 1;  // 该数字所属的数

    // 0 为个位、1 为最高位、2 为次高位……
    if (r == 0) {
      return num % 10;
    }

    int res;
    for (int i = 0; i < m - r + 1; ++i) {
      res = num % 10;
      num /= 10;
    }

    return res;
  }
};
// @lc code=end
