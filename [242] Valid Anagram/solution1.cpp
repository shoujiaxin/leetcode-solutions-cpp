/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.89%)
 * Likes:    1179
 * Dislikes: 129
 * Total Accepted:    488.5K
 * Total Submissions: 883.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    array<int, 26> charCnt{0};

    for (const auto& ch : s) {
      ++charCnt[ch - 'a'];
    }

    for (const auto& ch : t) {
      if (charCnt[ch - 'a'] == 0) {
        return false;
      }
      --charCnt[ch - 'a'];
    }

    return accumulate(charCnt.cbegin(), charCnt.cend(), 0) == 0;
  }
};
// @lc code=end
