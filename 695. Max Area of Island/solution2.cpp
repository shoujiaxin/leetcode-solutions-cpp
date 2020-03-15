/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    1538
 * Dislikes: 69
 * Total Accepted:    127K
 * Total Submissions: 209.4K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 *
 * Example 1:
 *
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 *
 * Example 2:
 *
 *
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 * Note: The length of each dimension in the given grid does not exceed 50.
 *
 */

// @lc code=start
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int maxArea = 0;
    for (auto i = 0; i < grid.size(); ++i) {
      for (auto j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          maxArea = max(bfs(grid, i, j), maxArea);
        }
      }
    }

    return maxArea;
  }

 private:
  /// 迭代实现广度优先遍历
  /// @param grid 二维数组
  /// @param x 当前元素行坐标
  /// @param y 当前元素列坐标
  int bfs(vector<vector<int>>& grid, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    int area = 0;

    while (!q.empty()) {
      auto i = q.front().first;
      auto j = q.front().second;
      q.pop();

      if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
          grid[i][j] == 1) {
        grid[i][j] = 0;

        ++area;

        q.push({i + 1, j});
        q.push({i, j + 1});
        q.push({i - 1, j});
        q.push({i, j - 1});
      }
    }

    return area;
  }
};
// @lc code=end
