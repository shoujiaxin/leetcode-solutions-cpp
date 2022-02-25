/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 *
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (74.99%)
 * Likes:    746
 * Dislikes: 144
 * Total Accepted:    153.4K
 * Total Submissions: 204.4K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * Given a binary matrix A, we want to flip the image horizontally, then invert
 * it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is
 * replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 *
 * Example 1:
 *
 *
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row:
 * [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *
 *
 * Notes:
 *
 *
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto& row : A) {
      auto left = row.begin();
      auto right = row.end() - 1;

      while (left <= right) {
        if (left == right) {
          *left = 1 - *left;
          break;
        }

        *left = 1 - *left;
        *right = 1 - *right;

        swap(*left, *right);

        ++left;
        --right;
      }
    }

    return A;
  }
};
// @lc code=end
