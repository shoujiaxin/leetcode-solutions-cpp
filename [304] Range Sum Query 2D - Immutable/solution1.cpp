/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (47.76%)
 * Likes:    2546
 * Dislikes: 247
 * Total Accepted:    225K
 * Total Submissions: 470.4K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, handle multiple queries of the following
 * type:
 *
 *
 * Calculate the sum of the elements of matrix inside the rectangle defined by
 * its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 *
 * Implement the NumMatrix class:
 *
 *
 * NumMatrix(int[][] matrix) Initializes the object with the integer matrix
 * matrix.
 * int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the
 * elements of matrix inside the rectangle defined by its upper left corner
 * (row1, col1) and lower right corner (row2, col2).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
 * [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1,
 * 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
 * Output
 * [null, 8, 11, 12]
 *
 * Explanation
 * NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1,
 * 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green
 * rectangle)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue
 * rectangle)
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * At most 10^4 calls will be made to sumRegion.
 *
 *
 */

// @lc code=start
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return;
    }

    const auto m = matrix.size();
    const auto n = matrix[0].size();
    dp = vector<vector<int>>(m, vector<int>(n, 0));

    dp[0][0] = matrix[0][0];
    for (auto i = 1; i < m; ++i) {
      dp[i][0] = matrix[i][0] + dp[i - 1][0];
    }
    for (auto i = 1; i < n; ++i) {
      dp[0][i] = matrix[0][i] + dp[0][i - 1];
    }

    for (auto i = 1; i < m; ++i) {
      for (auto j = 1; j < n; ++j) {
        dp[i][j] =
            matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    auto a = dp[row2][col2];
    auto b = (row1 > 0) ? dp[row1 - 1][col2] : 0;
    auto c = (col1 > 0) ? dp[row2][col1 - 1] : 0;
    auto d = (row1 > 0 && col1 > 0) ? dp[row1 - 1][col1 - 1] : 0;

    return a - b - c + d;
  }

 private:
  vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
