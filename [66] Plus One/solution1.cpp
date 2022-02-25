/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.73%)
 * Likes:    1032
 * Dislikes: 1806
 * Total Accepted:    459.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    digits.back() += 1;

    for (auto i = digits.size() - 1; i > 0; --i) {
      if (digits[i] > 9) {
        digits[i] -= 10;
        digits[i - 1] += 1;
      }
    }

    if (digits[0] > 9) {
      digits[0] -= 10;
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
// @lc code=end
