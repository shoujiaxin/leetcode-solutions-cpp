/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (42.90%)
 * Likes:    652
 * Dislikes: 165
 * Total Accepted:    280.5K
 * Total Submissions: 653.8K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: true
 * Explanation: 2^0 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 *
 * Example 3:
 *
 *
 * Input: 218
 * Output: false
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    bool hasOne = false;

    while (n) {
      if (n & 1) {
        if (hasOne) {
          return false;
        }
        hasOne = true;
      }

      n >>= 1;
    }

    return hasOne;
  }
};
// @lc code=end
