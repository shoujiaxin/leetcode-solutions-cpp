/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (33.69%)
 * Likes:    538
 * Dislikes: 79
 * Total Accepted:    91.8K
 * Total Submissions: 283.9K
 * Testcase Example:  '[2,1]'
 *
 * Given an array A of integers, return true if and only if it is a valid
 * mountain array.
 *
 * Recall that A is a mountain array if and only if:
 *
 *
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 *
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [2,1]
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [3,5,5]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [0,3,2,1]
 * Output: true
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    auto left = 0;
    int right = A.size() - 1;

    while (left < right && A[left] < A[left + 1]) {
      ++left;
    }
    while (left < right && A[right - 1] > A[right]) {
      --right;
    }

    return left == right && left != 0 && left != A.size() - 1;
  }
};
// @lc code=end
