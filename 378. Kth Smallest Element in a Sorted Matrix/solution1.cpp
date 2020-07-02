/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (53.03%)
 * Likes:    2328
 * Dislikes: 125
 * Total Accepted:    184.1K
 * Total Submissions: 342.1K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto n = matrix.size();
    vector<int> nums(n * n, 0);

    for (auto i = 0; i < n * n; ++i) {
      nums[i] = matrix[i / n][i % n];
    }

    return nums[k - 1];
  }
};
// @lc code=end
