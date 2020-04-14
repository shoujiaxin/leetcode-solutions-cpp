/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (41.23%)
 * Likes:    431
 * Dislikes: 191
 * Total Accepted:    140.8K
 * Total Submissions: 341.4K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 *
 * Example 1:
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 5
 * Output: false
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfFour(int num) {
    if (num < 1) {
      return false;
    }

    // 换底公式
    double res = log10(num) / log10(4);
    return static_cast<int>(res) == res;
  }
};
// @lc code=end
