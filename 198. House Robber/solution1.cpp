/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.67%)
 * Likes:    4037
 * Dislikes: 124
 * Total Accepted:    462.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 *
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    // dp[i] 表示前 i 个房子能偷到的最大金额
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];

    for (auto i = 2; i <= nums.size(); ++i) {
      // dp[i - 1] 表示不偷第 i 个房子
      // dp[i - 2] + nums[i - 1] 表示偷第 i 个房子
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    return dp.back();
  }
};
// @lc code=end
