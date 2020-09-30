/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (55.98%)
 * Likes:    3620
 * Dislikes: 259
 * Total Accepted:    458.3K
 * Total Submissions: 793.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: [[1]]
 *
 *
 * Example 4:
 *
 *
 * Input: matrix = [[1,2],[3,4]]
 * Output: [[3,1],[4,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * matrix.length == n
 * matrix[i].length == n
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    auto top = 0;
    auto bottom = n - 1;
    auto left = 0;
    auto right = n - 1;

    while (bottom > top && right > left) {
      for (auto cnt = 0; cnt < bottom - top; ++cnt) {
        auto temp = matrix[top][left];

        for (auto i = top; i < bottom; ++i) {
          matrix[i][left] = matrix[i + 1][left];
        }
        for (auto i = left; i < right; ++i) {
          matrix[bottom][i] = matrix[bottom][i + 1];
        }
        for (auto i = bottom; i > top; --i) {
          matrix[i][right] = matrix[i - 1][right];
        }
        for (auto i = right; i > left; --i) {
          matrix[top][i] = matrix[top][i - 1];
        }

        matrix[top][left + 1] = temp;
      }

      ++top;
      --bottom;
      ++left;
      --right;
    }
  }
};
// @lc code=end
