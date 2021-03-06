/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (41.42%)
 * Likes:    2483
 * Dislikes: 162
 * Total Accepted:    202.2K
 * Total Submissions: 488K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;

    for (const auto &c : p) {
      ++need[c];
    }

    auto left = 0, right = 0, valid = 0;
    vector<int> res;

    while (right < s.size()) {
      auto c = s[right];
      ++right;

      if (need.find(c) != need.end()) {
        ++window[c];
        if (window[c] == need[c]) {
          ++valid;
        }
      }

      while (right - left >= p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
        }

        auto d = s[left];
        ++left;

        if (need.find(d) != need.end()) {
          if (window[d] == need[d]) {
            --valid;
          }
          --window[d];
        }
      }
    }

    return res;
  }
};
// @lc code=end
