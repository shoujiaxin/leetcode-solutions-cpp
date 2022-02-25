/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.95%)
 * Likes:    440
 * Dislikes: 1371
 * Total Accepted:    239.5K
 * Total Submissions: 570.7K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Example 1:
 *
 *
 * Input: 27
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: 0
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: 9
 * Output: true
 *
 * Example 4:
 *
 *
 * Input: 45
 * Output: false
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n < 1) {
      return false;
    }

    // 换底公式
    double res = log10(n) / log10(3);
    return static_cast<int>(res) == res;
  }
};
// @lc code=end
