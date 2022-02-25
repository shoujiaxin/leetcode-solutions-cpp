/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.17%)
 * Likes:    2725
 * Dislikes: 123
 * Total Accepted:    434.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }

    auto left = 0;
    auto right = nums.size();

    // 第一个
    while (left < right) {
      auto mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    auto first = (left < nums.size() && nums[left] == target) ? left : -1;
    if (first == -1) {
      return {-1, -1};
    }

    right = nums.size();

    // 最后一个
    while (left < right) {
      auto mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    auto last = --left;

    return {first, last};
  }
};
// @lc code=end
