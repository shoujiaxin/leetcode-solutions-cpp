/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (31.49%)
 * Likes:    4379
 * Dislikes: 161
 * Total Accepted:    347.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<int> maxDp(nums);  // 以 nums[i] 结尾的乘积最大子数组的乘积
    vector<int> minDp(nums);  // 以 nums[i] 结尾的乘积最小子数组的乘积

    for (auto i = 1; i < nums.size(); ++i) {
      maxDp[i] =
          max({maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i], maxDp[i]});
      minDp[i] =
          min({minDp[i - 1] * nums[i], maxDp[i - 1] * nums[i], minDp[i]});
    }

    return *max_element(maxDp.cbegin(), maxDp.cend());
  }
};
// @lc code=end
