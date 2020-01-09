/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.91%)
 * Likes:    604
 * Dislikes: 202
 * Total Accepted:    132.7K
 * Total Submissions: 291K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string addStrings(string num1, string num2) {
    std::string result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    short sum = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || sum != 0) {
      if (it1 != num1.rend()) {
        sum += *(it1++) - '0';
      }
      if (it2 != num2.rend()) {
        sum += *(it2++) - '0';
      }
      result += std::to_string(sum % 10);
      sum /= 10;
    }

    std::reverse(result.begin(), result.end());

    return result;
  }
};
// @lc code=end
