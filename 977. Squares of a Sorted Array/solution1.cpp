/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.24%)
 * Likes:    1521
 * Dislikes: 101
 * Total Accepted:    316.2K
 * Total Submissions: 438.2K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    auto pivot = 0;
    auto minAbs = abs(A[pivot]);
    for (auto i = 1; i < A.size(); ++i) {
      if (abs(A[i]) <= minAbs) {
        minAbs = abs(A[i]);
        pivot = i;
      } else {
        break;
      }
    }

    auto left = pivot - 1;
    auto right = pivot + 1;

    vector<int> res{A[pivot] * A[pivot]};
    while (left >= 0 || right < A.size()) {
      auto n = INT_MAX;
      if (left >= 0) {
        n = min(n, A[left] * A[left]);
      }
      if (right < A.size()) {
        n = min(n, A[right] * A[right]);
      }

      res.push_back(n);

      if (left >= 0 && n == A[left] * A[left]) {
        --left;
      } else if (right < A.size() && n == A[right] * A[right]) {
        ++right;
      }
    }

    return res;
  }
};
// @lc code=end
