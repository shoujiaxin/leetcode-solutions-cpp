/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (19.54%)
 * Likes:    868
 * Dislikes: 2670
 * Total Accepted:    363.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 *
 * Note:
 *
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 *
 *
 *
 *
 * Follow up:
 *
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    auto left = s.find_first_not_of(' ');
    if (left == string::npos) {
      return "";
    }
    auto right = s.find_last_not_of(' ');
    s = s.substr(left, right - left + 1);

    auto b = s.begin();
    while (b != s.end()) {
      while (b != s.end() && isspace(*b)) {
        if (isspace(*(b - 1))) {
          s.erase(b);
        } else {
          ++b;
        }
      }

      auto it = b;
      while (it != s.end() && !isspace(*it)) {
        ++it;
      }

      reverse(b, it);  // 翻转每个单词
      b = it;
    }

    reverse(s.begin(), s.end());  // 翻转整个句子
    return s;
  }
};
// @lc code=end
