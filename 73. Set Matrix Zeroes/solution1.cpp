/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.07%)
 * Likes:    1691
 * Dislikes: 278
 * Total Accepted:    283K
 * Total Submissions: 670.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
      return;
    }

    unordered_set<int> rows;
    unordered_set<int> cols;

    for (auto i = 0; i < matrix.size(); ++i) {
      for (auto j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (const auto &row : rows) {
      for (auto i = 0; i < matrix[0].size(); ++i) {
        matrix[row][i] = 0;
      }
    }
    for (const auto &col : cols) {
      for (auto i = 0; i < matrix.size(); ++i) {
        matrix[i][col] = 0;
      }
    }
  }
};
// @lc code=end
