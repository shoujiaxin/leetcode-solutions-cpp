/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (51.71%)
 * Likes:    1605
 * Dislikes: 106
 * Total Accepted:    420.2K
 * Total Submissions: 812.2K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */

// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> charCnt;
    for (const auto &c : s) {
      ++charCnt[c];
    }

    for (auto i = 0; i < s.size(); ++i) {
      if (charCnt[s[i]] == 1) {
        return i;
      }
    }

    return -1;
  }
};
// @lc code=end
