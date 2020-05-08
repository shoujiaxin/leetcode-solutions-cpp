/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.64%)
 * Likes:    8077
 * Dislikes: 493
 * Total Accepted:    1.4M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    auto left = 0, right = 0;
    auto res = 0;

    while (right < s.size()) {
      auto c = s[right];
      ++right;

      ++window[c];

      while (window[c] > 1) {
        auto d = s[left];
        ++left;

        --window[d];
      }

      res = max(res, right - left);
    }

    return res;
  }
};
// @lc code=end
