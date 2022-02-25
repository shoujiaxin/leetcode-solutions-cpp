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
    // 数组是否被旋转
    if (nums.front() >= nums.back()) {
      // 倒序查找最小元素
      for (auto it = nums.rbegin(); it != nums.rend() - 1; ++it) {
        if (*(it + 1) > *it) {
          return *it;
        }
      }
    }

    return nums.front();  // 没有旋转，返回数组第一个元素
  }
};
// @lc code=end
