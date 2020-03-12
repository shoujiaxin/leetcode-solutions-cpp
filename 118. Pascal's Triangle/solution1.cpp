/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.37%)
 * Likes:    983
 * Dislikes: 87
 * Total Accepted:    317.1K
 * Total Submissions: 642.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) {
      return result;
    }

    result.push_back({1});

    for (auto i = 1; i < numRows; ++i) {
      vector<int> row(i + 1, 1);
      auto lastRow = result.back();

      for (auto j = 1; j < i; ++j) {
        row[j] = lastRow[j - 1] + lastRow[j];
      }

      result.push_back(row);
    }

    return result;
  }
};
// @lc code=end
