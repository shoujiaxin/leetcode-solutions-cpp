/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (43.72%)
 * Likes:    3885
 * Dislikes: 133
 * Total Accepted:    164.6K
 * Total Submissions: 375.8K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Given an array of integers nums and an integer k, return the number of
 * contiguous subarrays where the product of all the elements in the subarray
 * is strictly less than k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,5,2,6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are:
 * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3], k = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    auto res = 0;

    auto l = 0;
    auto r = 0;
    auto prod = 1;
    while (r < nums.size()) {
      prod *= nums[r];
      while (l <= r && prod >= k) {
        prod /= nums[l];
        ++l;
      }
      res += r - l + 1;
      ++r;
    }

    return res;
  }
};
// @lc code=end
