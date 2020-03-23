/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (38.79%)
 * Likes:    1378
 * Dislikes: 84
 * Total Accepted:    132.8K
 * Total Submissions: 341.8K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */

// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n == 0) {
      return 0;
    }

    vector<int> dp(n, 1);
    int p2 = 0;  // 指向 x2 得到的数
    int p3 = 0;  // 指向 x3 得到的数
    int p5 = 0;  // 指向 x5 得到的数

    for (int i = 1; i < n; ++i) {
      dp[i] = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});

      // 可能有重复数字，不是 if-else 关系！！！
      if (dp[i] == dp[p2] * 2) {
        ++p2;
      }
      if (dp[i] == dp[p3] * 3) {
        ++p3;
      }
      if (dp[i] == dp[p5] * 5) {
        ++p5;
      }
    }

    return dp[n - 1];
  }
};
// @lc code=end
