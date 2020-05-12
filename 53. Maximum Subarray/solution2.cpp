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

    // dp[i] 表示以 nums[i] 结尾的连续子数组的最大和
    vector<int> dp(nums.cbegin(), nums.cend());

    for (auto i = 1; i < nums.size(); ++i) {
      dp[i] += max(dp[i - 1], 0);
    }

    return *max_element(dp.cbegin(), dp.cend());
  }
};
// @lc code=end
