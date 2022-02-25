/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (60.33%)
 * Likes:    2850
 * Dislikes: 116
 * Total Accepted:    196.8K
 * Total Submissions: 324K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 *
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 *
 * Example 1:
 *
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 *
 * Note:
 *
 *
 * The input string length won't exceed 1000.
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    auto res = 0;

    for (auto i = 0; i < s.size() * 2 - 1; ++i) {
      auto l = i / 2;
      auto r = i / 2 + i % 2;

      while (l >= 0 && r < s.size() && s[l] == s[r]) {
        --l;
        ++r;
        ++res;
      }
    }

    return res;
  }
};
// @lc code=end
