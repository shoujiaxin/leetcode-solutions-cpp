/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.97%)
 * Likes:    647
 * Dislikes: 137
 * Total Accepted:    150.8K
 * Total Submissions: 367.8K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
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
 * Input: 14
 * Output: false
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
    // 牛顿迭代法
    long root = num;

    while (root * root > num) {
      root = (root + num / root) / 2;
    }

    return root * root == num;
  }
};
// @lc code=end
