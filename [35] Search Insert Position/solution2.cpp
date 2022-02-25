/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (42.55%)
 * Likes:    2421
 * Dislikes: 256
 * Total Accepted:    644.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) {
      return 0;
    }

    if (target > nums.back()) {
      return nums.size();
    }

    auto left = 0;
    auto right = nums.size() - 1;

    while (left < right) {
      auto mid = left + (right - left) / 2;

      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
// @lc code=end
