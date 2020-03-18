/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (60.05%)
 * Likes:    4266
 * Dislikes: 234
 * Total Accepted:    481.6K
 * Total Submissions: 801.2K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    backtrack(n, "", 0, 0);
    return res;
  }

 private:
  vector<string> res;

  void backtrack(int n, string str, int open, int close) {
    if (str.size() == 2 * n) {
      res.push_back(str);
      return;
    }

    if (open < n) {
      backtrack(n, str + "(", open + 1, close);
    }
    if (close < open) {
      backtrack(n, str + ")", open, close + 1);
    }
  }
};
// @lc code=end
