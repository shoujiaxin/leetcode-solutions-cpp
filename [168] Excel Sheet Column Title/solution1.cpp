/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.71%)
 * Likes:    925
 * Dislikes: 193
 * Total Accepted:    195.1K
 * Total Submissions: 650.6K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 *
 *
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 * ⁠   ...
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "A"
 *
 *
 * Example 2:
 *
 *
 * Input: 28
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: 701
 * Output: "ZY"
 *
 */

// @lc code=start
class Solution {
 public:
  string convertToTitle(int n) {
    std::string title = "";

    while (n > 26) {
      title += (n % 26 == 0) ? 'Z' : n % 26 + 'A' - 1;

      if (n % 26 == 0) {
        n = n / 26 - 1;
      } else {
        n /= 26;
      }
    }
    title += std::string(1, n + 'A' - 1);

    std::reverse(title.begin(), title.end());

    return title;
  }
};
// @lc code=end
