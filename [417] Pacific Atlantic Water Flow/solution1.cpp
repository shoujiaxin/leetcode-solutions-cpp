/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (46.99%)
 * Likes:    3547
 * Dislikes: 806
 * Total Accepted:    195.3K
 * Total Submissions: 397.8K
 * Testcase Example:
 * '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 *
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 *
 *
 * Example 1:
 *
 *
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [[2,1],[1,2]]
 * Output: [[0,0],[0,1],[1,0],[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    for (auto i = 0; i < m; ++i) {
      dfs(heights, pacific, i, 0);
      dfs(heights, atlantic, i, n - 1);
    }

    for (auto i = 0; i < n; ++i) {
      dfs(heights, pacific, 0, i);
      dfs(heights, atlantic, m - 1, i);
    }

    vector<vector<int>> res;
    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          res.emplace_back(vector<int>{i, j});
        }
      }
    }
    return res;
  }

 private:
  int m;
  int n;
  const vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& mark,
           int i, int j) {
    mark[i][j] = true;

    for (const auto& dir : dirs) {
      const auto nextI = i + dir[0];
      const auto nextJ = j + dir[1];
      if (nextI >= 0 && nextJ >= 0 && nextI < m && nextJ < n &&
          heights[nextI][nextJ] >= heights[i][j] && !mark[nextI][nextJ]) {
        dfs(heights, mark, nextI, nextJ);
      }
    }
  }
};
// @lc code=end
