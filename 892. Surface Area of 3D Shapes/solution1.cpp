/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 *
 * https://leetcode.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (57.95%)
 * Likes:    212
 * Dislikes: 275
 * Total Accepted:    16.1K
 * Total Submissions: 27.8K
 * Testcase Example:  '[[2]]'
 *
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of
 * grid cell (i, j).
 *
 * Return the total surface area of the resulting shapes.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[2]]
 * Output: 10
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,2],[3,4]]
 * Output: 34
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [[1,0],[0,2]]
 * Output: 16
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 *
 *
 *
 * Example 5:
 *
 *
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 *
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    auto len = grid.size();
    int res = 0;

    // 计算每个格子中立方体的表面积
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (grid[i][j]) {
          res += 4 * grid[i][j] + 2;
        }
      }
    }

    // 减去两列之间遮挡的面积
    for (int i = 0; i < len; ++i) {
      for (int j = 1; j < len; ++j) {
        res -= 2 * min(grid[i][j], grid[i][j - 1]);
      }
    }

    // 减去两行之间遮挡的面积
    for (int j = 0; j < len; ++j) {
      for (int i = 1; i < len; ++i) {
        res -= 2 * min(grid[i][j], grid[i - 1][j]);
      }
    }

    return res;
  }
};
// @lc code=end
