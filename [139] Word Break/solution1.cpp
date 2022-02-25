/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (38.95%)
 * Likes:    4168
 * Dislikes: 228
 * Total Accepted:    540.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
    auto len = s.size();

    // dp[i] 表示 s 的前 i 个字符是否可以拆分
    vector<bool> dp(len + 1, false);
    dp[0] = true;

    for (auto i = 1; i <= len; ++i) {
      for (auto j = 0; j < i; ++j) {
        if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
          // s 的前 s 个字符可以拆分成 s[0, j - 1] 和 s[j, i - 1] 两个单词
          dp[i] = true;
          break;
        }
      }
    }

    return dp.back();
  }
};
// @lc code=end
