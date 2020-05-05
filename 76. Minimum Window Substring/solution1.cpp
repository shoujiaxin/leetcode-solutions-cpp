/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.65%)
 * Likes:    3933
 * Dislikes: 275
 * Total Accepted:    365.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;

    for (const auto& c : t) {
      ++need[c];
    }

    auto left = 0, right = 0, valid = 0;
    auto start = 0, len = INT_MAX;

    while (right < s.size()) {
      auto c = s[right];  // 移入窗口的字符
      ++right;

      if (need.find(c) != need.end()) {
        ++window[c];
        if (window[c] == need[c]) {
          ++valid;
        }
      }

      while (valid == need.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }

        auto d = s[left];  // 移出窗口的字符
        ++left;

        if (need.find(d) != need.end()) {
          if (window[d] == need[d]) {
            --valid;
          }
          --window[d];
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
// @lc code=end
