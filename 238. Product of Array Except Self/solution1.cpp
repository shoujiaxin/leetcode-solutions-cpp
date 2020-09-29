/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (59.81%)
 * Likes:    5643
 * Dislikes: 460
 * Total Accepted:    605K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Example:
 *
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 *
 * Constraint: It's guaranteed that the product of the elements of any prefix
 * or suffix of the array (including the whole array) fits in a 32 bit
 * integer.
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 0);

    auto temp = 1;
    for (auto i = 0; i < nums.size(); ++i) {
      res[i] = temp;
      temp *= nums[i];
    }

    temp = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      res[i] *= temp;
      temp *= nums[i];
    };

    return res;
  }
};
// @lc code=end
