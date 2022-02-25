/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.56%)
 * Likes:    3018
 * Dislikes: 129
 * Total Accepted:    262.8K
 * Total Submissions: 951.7K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    int maxLen = 0;

    // dp[i] 表示以 s[i] 结尾的最长有效括号的长度
    vector<int> dp(s.size(), 0);

    for (auto i = 1; i < s.size(); ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] =
              dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] + 2 : 2);
        }

        maxLen = max(maxLen, dp[i]);
      }
    }

    return maxLen;
  }
};
// @lc code=end
