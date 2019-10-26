/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.95%)
 * Likes:    1201
 * Dislikes: 224
 * Total Accepted:    350.9K
 * Total Submissions: 855.7K
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
 */

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.size() < b.size()) {
      return addBinary(b, a);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (decltype(b.size()) i = 0; i != b.size(); ++i) {
      a[i] = a[i] + b[i] - '0';
    }

    for (decltype(a.size()) i = 0; i != a.size(); ++i) {
      if (a[i] > '1') {
        a[i] -= 2;

        if (i != a.size() - 1) {
          ++a[i + 1];
        } else {
          a.push_back('1');
        }
      }
    }

    reverse(a.begin(), a.end());

    return a;
  }
};
// @lc code=end
