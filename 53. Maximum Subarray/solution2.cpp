/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.76%)
 * Likes:    6594
 * Dislikes: 296
 * Total Accepted:    808.8K
 * Total Submissions: 1.8M
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
    if (nums.empty()) {
      return 0;
    }

    auto len = nums.size();

    // dp[i] 表示包含第 i 个元素的最大子序和
    vector<int> dp(len, 0);
    dp[0] = nums[0];

    for (int i = 1; i < len; ++i) {
      dp[i] = max(dp[i - 1], 0) + nums[i];
    }

    return *max_element(dp.begin(), dp.end());
  }
};
// @lc code=end
