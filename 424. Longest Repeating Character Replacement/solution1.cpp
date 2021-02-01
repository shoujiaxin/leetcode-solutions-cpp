/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (48.03%)
 * Likes:    2054
 * Dislikes: 103
 * Total Accepted:    97.6K
 * Total Submissions: 202.9K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 *
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 *
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 10^4.
 *
 * Example 1:
 *
 *
 * Input:
 * s = "ABAB", k = 2
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "AABABBA", k = 1
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    auto cnt = array<int, 26>();
    auto left = 0;
    auto maxCnt = 0;  // 窗口中出现最多字符的个数
    auto res = 0;

    for (auto right = 0; right < s.size(); ++right) {
      ++cnt[s[right] - 'A'];
      maxCnt = max(maxCnt, cnt[s[right] - 'A']);

      // right - left + 1 - maxCnt 为窗口中除出现最多字符以外其他字符的个数
      // 即需要替换的字符的个数
      if (right - left + 1 - maxCnt > k) {
        --cnt[s[left] - 'A'];
        ++left;
      }

      res = max(res, right - left + 1);
    }

    return res;
  }
};
// @lc code=end
