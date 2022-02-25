/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (47.48%)
 * Likes:    685
 * Dislikes: 193
 * Total Accepted:    261.3K
 * Total Submissions: 550.3K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);

    for (auto i = 0; i <= rowIndex; ++i) {
      for (auto j = i; j > 1; --j) {
        row[j - 1] = row[j - 2] + row[j - 1];
      }
    }

    return row;
  }
};
// @lc code=end
