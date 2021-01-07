/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (59.95%)
 * Likes:    2563
 * Dislikes: 168
 * Total Accepted:    223.3K
 * Total Submissions: 372.4K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    auto n = isConnected.size();
    visited = vector<bool>(n, false);

    auto res = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = i; j < n; ++j) {
        res += dfs(isConnected, i, j);
      }
    }

    return res;
  }

 private:
  vector<bool> visited;

  int dfs(const vector<vector<int>>& isConnected, int x, int y) {
    if (visited[y]) {
      return 0;
    }
    if (!isConnected[x][y]) {
      return 0;
    }

    visited[y] = true;

    auto res = isConnected[x][y];
    for (auto i = 0; i < isConnected.size(); ++i) {
      if (isConnected[y][i]) {
        res += dfs(isConnected, y, i);
      }
    }

    return res > 0 ? 1 : 0;
  }
};
// @lc code=end
