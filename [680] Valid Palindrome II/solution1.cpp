/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (39.40%)
 * Likes:    5587
 * Dislikes: 300
 * Total Accepted:    494.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aba"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abc"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (s[left] == s[right]) {
        ++left;
        --right;
      } else {
        return valid(s, left, right - 1) || valid(s, left + 1, right);
      }
    }

    return true;
  }

 private:
  bool valid(const string_view& s, int begin, int end) {
    while (begin < end) {
      if (s[begin] != s[end]) {
        return false;
      }
      ++begin;
      --end;
    }
    return true;
  }
};
// @lc code=end
