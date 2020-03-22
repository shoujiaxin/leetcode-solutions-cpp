/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.10%)
 * Likes:    4567
 * Dislikes: 414
 * Total Accepted:    686.9K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    auto len = s.size();
    if (len < 2) {
      return s;
    }

    int start = 0;   // 记录回文串开始位置
    int maxLen = 1;  // 记录回文串最大长度，单个字符必回文

    // dp[i][j] 表示 s[i, j] 是否回文 (j < j)
    vector<vector<bool>> dp(len, vector<bool>(len, false));

    for (int i = 0; i < len; ++i) {
      dp[i][i] = true;  // 单个字符必回文
    }

    for (int j = 1; j < len; ++j) {
      for (int i = 0; i < j; ++i) {
        if (s[i] == s[j]) {
          // 若长度小于等于 3，且首位字符相同，则必回文
          dp[i][j] = (j - i < 3) ? true : dp[i + 1][j - 1];
        }

        if (dp[i][j] && j - i + 1 > maxLen) {
          start = i;
          maxLen = j - i + 1;
        }
      }
    }

    return s.substr(start, maxLen);
  }
};
// @lc code=end
