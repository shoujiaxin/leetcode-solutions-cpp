/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.75%)
 * Likes:    206
 * Dislikes: 141
 * Total Accepted:    51.8K
 * Total Submissions: 113.2K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *
 * Input: 100
 * Output: "202"
 *
 *
 *
 * Example 2:
 *
 * Input: -7
 * Output: "-10"
 *
 *
 *
 * Note:
 * The input will be in range of [-1e7, 1e7].
 *
 */

// @lc code=start
class Solution {
 public:
  string convertToBase7(int num) {
    if (num == 0) {
      return "0";
    }

    string res;
    auto n = abs(num);

    while (n) {
      res += n % 7 + '0';
      n /= 7;
    }

    if (num < 0) {
      res += '-';
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
// @lc code=end
