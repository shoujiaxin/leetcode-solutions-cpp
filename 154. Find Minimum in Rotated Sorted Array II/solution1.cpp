/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.89%)
 * Likes:    681
 * Dislikes: 191
 * Total Accepted:    161K
 * Total Submissions: 399.8K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5]
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: [2,2,2,0,1]
 * Output: 0
 *
 * Note:
 *
 *
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    auto left = nums.cbegin();
    auto right = nums.cend() - 1;

    // 二分查找
    // *mid > *right: 最小值位于 [mid + 1, rihgt]
    // *mid < *right: 最小值 [left, mid]
    // *mid == *right: 减小搜索范围
    // 最终 left 指向最小元素
    while (left != right) {
      auto mid = left + (right - left) / 2;

      if (*mid > *right) {
        left = mid + 1;
      } else if (*mid < *right) {
        right = mid;
      } else {
        --right;
      }
    }

    return *left;
  }
};
// @lc code=end
