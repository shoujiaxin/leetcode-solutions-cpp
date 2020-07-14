/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (43.73%)
 * Likes:    1977
 * Dislikes: 238
 * Total Accepted:    247.4K
 * Total Submissions: 564.7K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */

// @lc code=start
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    auto n = triangle.size();

    // dp[i][j] 表示移动到结点 [i][j] 时的最小路径和
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];

    for (auto i = 1; i < n; ++i) {
      // 每行第一个结点
      dp[i][0] = dp[i - 1][0] + triangle[i][0];

      for (auto j = 1; j < i; ++j) {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }

      // 每行最后一个结点
      dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    return *min_element(dp.back().cbegin(), dp.back().cend());
  }
};
// @lc code=end
