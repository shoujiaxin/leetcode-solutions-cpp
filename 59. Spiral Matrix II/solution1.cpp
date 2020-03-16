/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.48%)
 * Likes:    794
 * Dislikes: 101
 * Total Accepted:    175.4K
 * Total Submissions: 340.7K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    int left = 0;
    int top = 0;
    int right = n - 1;
    int bottom = n - 1;

    int currNum = 0;

    while (true) {
      // 从左到右
      for (auto i = left; i <= right; ++i) {
        res[top][i] = ++currNum;
      }
      if (++top > bottom) {
        break;
      }

      // 从上到下
      for (auto i = top; i <= bottom; ++i) {
        res[i][right] = ++currNum;
      }
      if (--right < left) {
        break;
      }

      // 从右到左
      for (auto i = right; i >= left; --i) {
        res[bottom][i] = ++currNum;
      }
      if (--bottom < top) {
        break;
      }

      // 从下到上
      for (auto i = bottom; i >= top; --i) {
        res[i][left] = ++currNum;
      }
      if (++left > right) {
        break;
      }
    }

    return res;
  }
};
// @lc code=end
