
/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.56%)
 * Likes:    3018
 * Dislikes: 129
 * Total Accepted:    262.8K
 * Total Submissions: 951.7K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    int maxLen = 0;

    stack<int> stk;
    stk.push(-1);

    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) {
          stk.push(i);
        } else {
          maxLen = max(maxLen, i - stk.top());
        }
      }
    }

    return maxLen;
  }
};
// @lc code=end
