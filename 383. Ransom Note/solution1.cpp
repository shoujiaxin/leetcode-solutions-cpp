/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (51.70%)
 * Likes:    464
 * Dislikes: 165
 * Total Accepted:    142.6K
 * Total Submissions: 275.7K
 * Testcase Example:  '"a"\n"b"'
 *
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 *
 *
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 *
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 *
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> charCnt;
    for (const auto& c : magazine) {
      ++charCnt[c];
    }

    for (const auto& c : ransomNote) {
      if (charCnt[c] > 0) {
        --charCnt[c];
      } else {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
