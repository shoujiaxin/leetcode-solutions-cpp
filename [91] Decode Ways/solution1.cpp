/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.72%)
 * Likes:    2205
 * Dislikes: 2450
 * Total Accepted:    353K
 * Total Submissions: 1.5M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */

// @lc code=start
class Solution {
 public:
  int numDecodings(string s) {
    if (s.front() == '0') {
      return 0;  // 以 '0' 开头，无法解码
    }

    auto len = s.size();
    // dp[i] 表示前 i 个字符的解码方法，dp[0] = 1 以统一形式
    vector<int> dp(len + 1, 1);

    for (int i = 2; i <= len; ++i) {
      auto val = 10 * (s[i - 2] - '0') + s[i - 1] - '0';

      if (s[i - 1] == '0') {
        if (val == 0 || val > 20) {
          return 0;  // 连续两个 ‘0’ 或大于 20 的整十数，无法解码
        }
        dp[i] = dp[i - 2];  // '1', '0' 或 '2', '0'
      } else if (val < 10 || val > 26) {
        dp[i] = dp[i - 1];  // 以 '0' 开头或大于 26 的两位数
      } else {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
    }

    return dp[len];
  }
};
// @lc code=end
