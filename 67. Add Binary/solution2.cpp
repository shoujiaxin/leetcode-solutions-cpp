/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (43.21%)
 * Likes:    1705
 * Dislikes: 268
 * Total Accepted:    441.8K
 * Total Submissions: 1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    auto len = max(a.size(), b.size()) + 1;
    auto res = string(len, '0');

    auto it = res.rbegin();
    auto it1 = a.rbegin();
    auto it2 = b.rbegin();

    while (it1 != a.rend() || it2 != b.rend()) {
      auto temp = *it - '0';

      if (it1 != a.rend()) {
        temp += *it1 - '0';
        ++it1;
      }
      if (it2 != b.rend()) {
        temp += *it2 - '0';
        ++it2;
      }

      if (temp > 1) {
        *(it + 1) = '1';
      }
      *it = temp % 2 + '0';
      ++it;
    }

    return res.front() == '0' ? res.substr(1) : res;
  }
};
// @lc code=end
