/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 *
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 *
 * algorithms
 * Easy (70.80%)
 * Likes:    853
 * Dislikes: 62
 * Total Accepted:    60.3K
 * Total Submissions: 85.1K
 * Testcase Example:  '[[3,7,8],[9,11,13],[15,16,17]]'
 *
 * Given an m x n matrix of distinct numbers, return all lucky numbers in the
 * matrix in any order.
 *
 * A lucky number is an element of the matrix such that it is the minimum
 * element in its row and maximum in its column.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * Output: [12]
 * Explanation: 12 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[7,8],[1,2]]
 * Output: [7]
 * Explanation: 7 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= n, m <= 50
 * 1 <= matrix[i][j] <= 10^5.
 * All elements in the matrix are distinct.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    const auto m = matrix.size();
    const auto n = matrix[0].size();

    auto rowMin = vector<int>(m, INT_MAX);
    auto colMax = vector<int>(n, INT_MIN);

    vector<int> result;
    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        rowMin[i] = min(rowMin[i], matrix[i][j]);
        colMax[j] = max(colMax[j], matrix[i][j]);
      }
    }

    for (const auto& r : rowMin) {
      for (const auto& c : colMax) {
        if (r == c) {
          result.push_back(r);
        }
      }
    }

    return result;
  }
};
// @lc code=end
