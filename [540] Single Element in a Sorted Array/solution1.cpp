/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (58.70%)
 * Likes:    4684
 * Dislikes: 108
 * Total Accepted:    273.6K
 * Total Submissions: 466K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 *
 * Return the single element that appears only once.
 *
 * Your solution must run in O(log n) time and O(1) space.
 *
 *
 * Example 1:
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      auto mid = (left + right) / 2;
      if (mid % 2 == 0) {
        if (nums[mid] == nums[mid - 1]) {
          right = mid - 2;
        } else if (nums[mid] == nums[mid + 1]) {
          left = mid + 2;
        } else {
          return nums[mid];
        }
      } else {
        if (nums[mid] == nums[mid - 1]) {
          left = mid + 1;
        } else if (nums[mid] == nums[mid + 1]) {
          right = mid - 1;
        } else {
          return nums[mid];
        }
      }
    }

    return nums[left];
  }
};
// @lc code=end
