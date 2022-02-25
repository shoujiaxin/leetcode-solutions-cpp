/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.65%)
 * Likes:    12199
 * Dislikes: 427
 * Total Accepted:    2.2M
 * Total Submissions: 5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (auto firstIter = nums.cbegin(); firstIter != nums.cend();
         ++firstIter) {
      for (auto secondIter = firstIter + 1; secondIter != nums.cend();
           ++secondIter) {
        if (*firstIter + *secondIter == target) {
          return {static_cast<int>(distance(nums.cbegin(), firstIter)),
                  static_cast<int>(distance(nums.cbegin(), secondIter))};
        }
      }
    }
    return {0, 0};
  }
};
// @lc code=end
