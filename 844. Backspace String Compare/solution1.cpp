/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.36%)
 * Likes:    1967
 * Dislikes: 98
 * Total Accepted:    244K
 * Total Submissions: 522.6K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 *
 * Note that after backspacing an empty text, the text will continue empty.
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 *
 *
 * Example 3:
 *
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 *
 *
 * Example 4:
 *
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 *
 *
 * Follow up:
 *
 *
 * Can you solve it in O(N) time and O(1) space?
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    stack<char> stk1;
    stack<char> stk2;

    for (const auto& ch : S) {
      if (ch == '#') {
        if (!stk1.empty()) {
          stk1.pop();
        }
      } else {
        stk1.push(ch);
      }
    }

    for (const auto& ch : T) {
      if (ch == '#') {
        if (!stk2.empty()) {
          stk2.pop();
        }
      } else {
        stk2.push(ch);
      }
    }

    while (!stk1.empty() && !stk2.empty()) {
      if (stk1.top() != stk2.top()) {
        return false;
      }

      stk1.pop();
      stk2.pop();
    }

    return stk1.empty() && stk2.empty();
  }
};
// @lc code=end
