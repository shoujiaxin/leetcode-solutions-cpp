/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (49.60%)
 * Likes:    781
 * Dislikes: 75
 * Total Accepted:    127.8K
 * Total Submissions: 257.6K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestPalindrome(string s) {
    if (s.empty()) {
      return 0;
    }

    unordered_map<char, int> charCnt;
    for (const auto& c : s) {
      ++charCnt[c];
    }

    int len = 0;
    for (const auto& p : charCnt) {
      // 只取偶数个相同的字符
      len += p.second / 2 * 2;

      // 取回文中心
      if (p.second % 2 == 1 && len % 2 == 0) {
        ++len;
      }
    }

    return len;
  }
};
// @lc code=end
