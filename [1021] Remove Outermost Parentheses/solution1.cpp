/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 *
 * https://leetcode.com/problems/remove-outermost-parentheses/description/
 *
 * algorithms
 * Easy (79.84%)
 * Likes:    1295
 * Dislikes: 1181
 * Total Accepted:    174K
 * Total Submissions: 217.9K
 * Testcase Example:  '"(()())(())"'
 *
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B,
 * where A and B are valid parentheses strings, and + represents string
 * concatenation.
 *
 *
 * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses
 * strings.
 *
 *
 * A valid parentheses string s is primitive if it is nonempty, and there does
 * not exist a way to split it into s = A + B, with A and B nonempty valid
 * parentheses strings.
 *
 * Given a valid parentheses string s, consider its primitive decomposition: s
 * = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
 *
 * Return s after removing the outermost parentheses of every primitive string
 * in the primitive decomposition of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()())(())"
 * Output: "()()()"
 * Explanation:
 * The input string is "(()())(())", with primitive decomposition "(()())" +
 * "(())".
 * After removing outer parentheses of each part, this is "()()" + "()" =
 * "()()()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(()())(())(()(()))"
 * Output: "()()()()(())"
 * Explanation:
 * The input string is "(()())(())(()(()))", with primitive decomposition
 * "(()())" + "(())" + "(()(()))".
 * After removing outer parentheses of each part, this is "()()" + "()" +
 * "()(())" = "()()()()(())".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "()()"
 * Output: ""
 * Explanation:
 * The input string is "()()", with primitive decomposition "()" + "()".
 * After removing outer parentheses of each part, this is "" + "" = "".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either '(' or ')'.
 * s is a valid parentheses string.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string res;
    auto cnt = 0;

    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        if (cnt++ == 0) {
          continue;
        }
      } else if (s[i] == ')') {
        if (--cnt == 0) {
          continue;
        }
      }
      res += s[i];
    }

    return res;
  }
};
// @lc code=end
