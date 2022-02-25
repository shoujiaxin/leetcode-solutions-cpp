/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (32.06%)
 * Likes:    2704
 * Dislikes: 69
 * Total Accepted:    144.2K
 * Total Submissions: 447.1K
 * Testcase Example:  '"()"'
 *
 * Given a string s containing only three types of characters: '(', ')' and
 * '*', return true if s is valid.
 *
 * The following rules define a valid string:
 *
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis
 * ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis
 * '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis
 * ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string "".
 *
 *
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 * Example 2:
 * Input: s = "(*)"
 * Output: true
 * Example 3:
 * Input: s = "(*))"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s[i] is '(', ')' or '*'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool checkValidString(string s) {
    stack<int> left;
    stack<int> star;

    for (auto i = 0; i < s.size(); ++i) {
      const auto &ch = s[i];
      switch (ch) {
        case '(':
          left.push(i);
          break;
        case '*':
          star.push(i);
          break;
        case ')':
          if (!left.empty()) {
            left.pop();
          } else if (!star.empty()) {
            star.pop();
          } else {
            return false;
          }
          break;
        default:
          break;
      }
    }

    while (!left.empty() && !star.empty()) {
      if (left.top() > star.top()) {
        return false;
      }
      left.pop();
      star.pop();
    }

    return left.empty();
  }
};
// @lc code=end
