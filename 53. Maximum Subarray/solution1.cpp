/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.84%)
 * Likes:    5341
 * Dislikes: 216
 * Total Accepted:    666.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    auto result = nums.front();
    auto sum = 0;

    for (const auto& n : nums) {
      if (sum > 0) {
        sum += n;
      } else {
        sum = n;
      }
      result = max(result, sum);
    }

    return result;
  }
};
// @lc code=end
