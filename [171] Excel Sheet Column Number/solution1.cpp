/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (52.53%)
 * Likes:    720
 * Dislikes: 132
 * Total Accepted:    254K
 * Total Submissions: 479.7K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28
 * ⁠   ...
 *
 *
 * Example 1:
 *
 *
 * Input: "A"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: "AB"
 * Output: 28
 *
 *
 * Example 3:
 *
 *
 * Input: "ZY"
 * Output: 701
 *
 */

// @lc code=start
class Solution {
 public:
  int titleToNumber(string s) {
    auto num = 0;

    for (const auto& c : s) {
      num *= 26;
      num += c - 'A' + 1;
    }

    return num;
  }
};
// @lc code=end
