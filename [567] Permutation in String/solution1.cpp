/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (40.62%)
 * Likes:    1145
 * Dislikes: 52
 * Total Accepted:    86.1K
 * Total Submissions: 212.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 *
 *
 *
 *
 * Note:
 *
 *
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;

    for (const auto& c : s1) {
      ++need[c];
    }

    auto left = 0, right = 0, valid = 0;

    while (right < s2.size()) {
      auto c = s2[right];
      ++right;

      if (need.find(c) != need.end()) {
        ++window[c];
        if (window[c] == need[c]) {
          ++valid;
        }
      }

      while (right - left >= s1.size()) {
        if (valid == need.size()) {
          return true;
        }

        auto d = s2[left];
        ++left;

        if (need.find(d) != need.end()) {
          if (window[d] == need[d]) {
            --valid;
          }
          --window[d];
        }
      }
    }

    return false;
  }
};
// @lc code=end
