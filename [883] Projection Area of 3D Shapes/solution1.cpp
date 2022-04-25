/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 *
 * https://leetcode.com/problems/projection-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (69.57%)
 * Likes:    392
 * Dislikes: 1141
 * Total Accepted:    40.3K
 * Total Submissions: 57.5K
 * Testcase Example:  '[[1,2],[3,4]]'
 *
 * You are given an n x n grid where we place some 1 x 1 x 1 cubes that are
 * axis-aligned with the x, y, and z axes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of the
 * cell (i, j).
 *
 * We view the projection of these cubes onto the xy, yz, and zx planes.
 *
 * A projection is like a shadow, that maps our 3-dimensional figure to a
 * 2-dimensional plane. We are viewing the "shadow" when looking at the cubes
 * from the top, the front, and the side.
 *
 * Return the total area of all three projections.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,2],[3,4]]
 * Output: 17
 * Explanation: Here are the three projections ("shadows") of the shape made
 * with each axis-aligned plane.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2]]
 * Output: 5
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,0],[0,2]]
 * Output: 8
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 50
 * 0 <= grid[i][j] <= 50
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    const auto n = grid.size();
    vector<int> rowMax(n, 0);
    vector<int> colMax(n, 0);
    auto res = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < n; ++j) {
        if (grid[i][j] > 0) {
          ++res;
        }
        rowMax[i] = max(rowMax[i], grid[i][j]);
        colMax[j] = max(colMax[j], grid[i][j]);
      }
    }
    res += accumulate(rowMax.cbegin(), rowMax.cend(), 0);
    res += accumulate(colMax.cbegin(), colMax.cend(), 0);
    return res;
  }
};
// @lc code=end
