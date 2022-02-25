/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (47.44%)
 * Likes:    363
 * Dislikes: 1061
 * Total Accepted:    79.8K
 * Total Submissions: 167.9K
 * Testcase Example:  '"abcdefg"\n2'
 *
 *
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 *
 *
 * Example:
 *
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 *
 *
 * Restrictions:
 *
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    auto it = s.begin();

    while (it < s.end()) {
      auto last = (it + k < s.end()) ? it + k : s.end();
      reverse(it, last);
      it += 2 * k;
    }

    return s;
  }
};
// @lc code=end
