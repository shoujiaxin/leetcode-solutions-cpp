/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (46.98%)
 * Likes:    4098
 * Dislikes: 240
 * Total Accepted:    564.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Follow up:
 *
 *
 * Could you solve this problem without using the library's sort function?
 * Could you come up with a one-pass algorithm using only O(1) constant
 * space?
 *
 *
 *
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    array<int, 3> cnt{0};
    for (const auto& n : nums) {
      ++cnt[n];
    }

    auto it = nums.begin();
    auto i = 0;
    while (it < nums.end() && i < 3) {
      for (auto j = 0; j < cnt[i]; ++j) {
        *it = i;
        ++it;
      }
      ++i;
    }
  }
};
// @lc code=end
