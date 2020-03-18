/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.65%)
 * Likes:    3913
 * Dislikes: 407
 * Total Accepted:    591.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }

    auto first = 0;
    auto last = nums.size() - 1;
    while (first < last) {
      auto mid = first + (last - first) / 2;
      if (nums[mid] < nums[last]) {
        last = mid;
      } else if (nums[mid] > nums[last]) {
        first = mid + 1;
      } else {
        --last;
      }
    }

    auto pivot = first;  // 旋转轴点（最小值）

    // 数组没有旋转
    if (pivot == 0) {
      return binarySearch(nums, 0, nums.size() - 1, target);
    }

    // 数组在 pivot 处旋转，分成两个递增的子序列进行二分查找
    if (nums[0] <= target && target <= nums[pivot - 1]) {
      return binarySearch(nums, 0, pivot - 1, target);
    } else {
      return binarySearch(nums, pivot, nums.size() - 1, target);
    }
  }

 private:
  int binarySearch(const vector<int>& arr, int first, int last, int target) {
    while (first <= last) {
      auto mid = first + (last - first) / 2;
      if (arr[mid] < target) {
        first = mid + 1;
      } else if (arr[mid] > target) {
        last = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
// @lc code=end
