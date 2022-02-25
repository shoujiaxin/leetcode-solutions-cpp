/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.41%)
 * Likes:    3489
 * Dislikes: 172
 * Total Accepted:    730.2K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    switch (s.size()) {
      case 0:
        return true;
      case 1:
        return false;
      default:
        break;
    }

    vector<char> charStack;
    for (const auto& c : s) {
      switch (c) {
        case '(':
        case '{':
        case '[':
          charStack.push_back(c);
          break;

        case ')':
          if (charStack.empty()) {
            return false;
          } else if (charStack.back() == '(') {
            charStack.pop_back();
            break;
          } else {
            return false;
          }

        case '}':
          if (charStack.empty()) {
            return false;
          } else if (charStack.back() == '{') {
            charStack.pop_back();
            break;
          } else {
            return false;
          }

        case ']':
          if (charStack.empty()) {
            return false;
          } else if (charStack.back() == '[') {
            charStack.pop_back();
            break;
          } else {
            return false;
          }

        default:
          return false;
      }
    }

    return charStack.empty();
  }
};
// @lc code=end
