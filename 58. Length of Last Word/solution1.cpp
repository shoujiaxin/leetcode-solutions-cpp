/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.32%)
 * Likes:    461
 * Dislikes: 1885
 * Total Accepted:    305.8K
 * Total Submissions: 946K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * Example:
 *
 *
 * Input: "Hello World"
 * Output: 5
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    while (s.back() == ' ') {
      s.pop_back();
    }

    auto pos = s.find_last_of(' ');
    return s.substr(pos + 1).size();
  }
};
// @lc code=end
