/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.84%)
 * Likes:    1841
 * Dislikes: 510
 * Total Accepted:    322.3K
 * Total Submissions: 981.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty() || matrix[0].empty()) {
      return res;
    }

    int left = 0;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;

    res.reserve((right + 1) * (bottom + 1));

    while (true) {
      // 从左到右
      for (int i = left; i <= right; ++i) {
        res.push_back(matrix[top][i]);
      }
      if (++top > bottom) {
        break;
      }

      // 从上到下
      for (int i = top; i <= bottom; ++i) {
        res.push_back(matrix[i][right]);
      }
      if (--right < left) {
        break;
      }

      // 从右到左
      for (int i = right; i >= left; --i) {
        res.push_back(matrix[bottom][i]);
      }
      if (--bottom < top) {
        break;
      }

      // 从下到上
      for (int i = bottom; i >= top; --i) {
        res.push_back(matrix[i][left]);
      }
      if (++left > right) {
        break;
      }
    }

    return res;
  }
};
// @lc code=end
