/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (56.58%)
 * Likes:    4060
 * Dislikes: 478
 * Total Accepted:    344.8K
 * Total Submissions: 609.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto i = 31; i >= 0; --i) {
      auto bit = 0;
      for (auto n : nums) {
        bit += (n >> i) & 1;
      }
      res <<= 1;
      res += bit % 3;
    }
    return res;
  }
};
// @lc code=end
