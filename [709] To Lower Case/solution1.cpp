/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (78.69%)
 * Likes:    432
 * Dislikes: 1408
 * Total Accepted:    192.9K
 * Total Submissions: 244.9K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "Hello"
 * Output: "hello"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "here"
 * Output: "here"
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "LOVELY"
 * Output: "lovely"
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string toLowerCase(string str) {
    for (auto& c : str) {
      if (isupper(c)) {
        c = tolower(c);
      }
    }

    return str;
  }
};
// @lc code=end
