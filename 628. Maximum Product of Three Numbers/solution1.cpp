/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (46.97%)
 * Likes:    1422
 * Dislikes: 418
 * Total Accepted:    139.6K
 * Total Submissions: 297.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums, find three numbers whose product is maximum and
 * return the maximum product.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 6
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 24
 * Example 3:
 * Input: nums = [-1,-2,-3]
 * Output: -6
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    auto n = nums.size();
    auto a = nums[n - 1] * nums[n - 2] * nums[n - 3];
    auto b = nums[0] * nums[1] * nums[n - 1];

    return max(a, b);
  }
};
// @lc code=end
