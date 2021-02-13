/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (51.91%)
 * Likes:    1238
 * Dislikes: 218
 * Total Accepted:    354.1K
 * Total Submissions: 679.9K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th row of the Pascal's
 * triangle.
 *
 * Notice that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    auto res = vector<int>(rowIndex + 1, 0);
    long cur = 1;

    // 第 n 行第 i 个数为 C(n, i) = n! / [i! * (n - i)!]
    // n 和 i 从 0 开始
    // 则第 i + 1 个数为第 i 个数的 (n - i) / (i + 1) 倍
    for (auto i = 0; i <= rowIndex; ++i) {
      res[i] = cur;
      cur = cur * (rowIndex - i) / (i + 1);
    }

    return res;
  }
};
// @lc code=end
