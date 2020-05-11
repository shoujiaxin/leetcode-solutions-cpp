/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (67.28%)
 * Likes:    585
 * Dislikes: 54
 * Total Accepted:    63.1K
 * Total Submissions: 93.7K
 * Testcase Example:  '"abbaca"'
 *
 * Given a string S of lowercase letters, a duplicate removal consists of
 * choosing two adjacent and equal letters, and removing them.
 *
 * We repeatedly make duplicate removals on S until we no longer can.
 *
 * Return the final string after all such duplicate removals have been made.
 * It is guaranteed the answer is unique.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "abbaca"
 * Output: "ca"
 * Explanation:
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent
 * and equal, and this is the only possible move.  The result of this move is
 * that the string is "aaca", of which only "aa" is possible, so the final
 * string is "ca".
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 20000
 * S consists only of English lowercase letters.
 *
 */

// @lc code=start
class Solution {
 public:
  string removeDuplicates(string S) {
    stack<char> stk;
    for (const auto &c : S) {
      if (!stk.empty() && stk.top() == c) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    string res(stk.size(), ' ');
    auto it = res.rbegin();
    while (it != res.rend()) {
      *it = stk.top();
      stk.pop();
      ++it;
    }

    return res;
  }
};
// @lc code=end
