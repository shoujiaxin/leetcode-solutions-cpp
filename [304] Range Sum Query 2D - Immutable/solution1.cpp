/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    1157
 * Dislikes: 188
 * Total Accepted:    126.1K
 * Total Submissions: 322.1K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 *
 *
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 *
 * Example:
 *
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 *
 * Note:
 *
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
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

    auto rows = matrix.size();
    auto cols = matrix[0].size();
    vector<vector<int>> temp(rows, vector<int>(cols, 0));
    temp[0][0] = matrix[0][0];
    for (auto i = 1; i < rows; ++i) {
      temp[i][0] = matrix[i][0] + temp[i - 1][0];
    }
    for (auto i = 1; i < cols; ++i) {
      temp[0][i] += matrix[0][i] + temp[0][i - 1];
    }

    for (auto i = 1; i < rows; ++i) {
      for (auto j = 1; j < cols; ++j) {
        temp[i][j] =
            matrix[i][j] + temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1];
      }
    }

    dp = std::move(temp);
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
