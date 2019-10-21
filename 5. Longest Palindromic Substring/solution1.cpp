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
    string longestStr;
    auto maxLength = longestStr.size();

    for (decltype(s.size()) i = 0; i != s.size(); ++i) {
      auto j = string::npos;

      while (s.rfind(s[i], j) != string::npos) {
        auto index = s.rfind(s[i], j);
        auto subStr = s.substr(i, index - i + 1);

        if (isPalindromic(subStr)) {
          if (subStr.size() > maxLength) {
            maxLength = subStr.size();
            longestStr = std::move(subStr);
          }
          break;
        }

        j = index - 1;
      }
    }

    return longestStr;
  }

 private:
  bool isPalindromic(const string& s) {
    for (decltype(s.size()) i = 0; i != s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
