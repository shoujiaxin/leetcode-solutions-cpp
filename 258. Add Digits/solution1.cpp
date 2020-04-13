/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (55.83%)
 * Likes:    628
 * Dislikes: 990
 * Total Accepted:    275.3K
 * Total Submissions: 492.9K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 *
 * Example:
 *
 *
 * Input: 38
 * Output: 2
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
 * Since 2 has only one digit, return it.
 *
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

// @lc code=start
class Solution {
 public:
  int addDigits(int num) {
    while (num > 9) {
      auto temp = 0;
      while (num) {
        temp += num % 10;
        num /= 10;
      }
      num = temp;
    }

    return num;
  }
};
// @lc code=end
