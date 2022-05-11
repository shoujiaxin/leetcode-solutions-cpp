/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (39.89%)
 * Likes:    5435
 * Dislikes: 92
 * Total Accepted:    393.8K
 * Total Submissions: 986.8K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
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
    const int n = nums.size();

    // dp[i] 表示前 i 个房子能偷到的最大金额
    vector<int> dp1(n + 1, 0);
    // 偷第一个房子，不能偷最后一个
    dp1[1] = nums[0];
    for (auto i = 2; i < n; ++i) {
      dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
    }

    // dp[i] 表示前 i 个房子能偷到的最大金额
    vector<int> dp2(n + 1, 0);
    // 不偷第一个房子，可以偷最后一个
    for (auto i = 2; i <= n; ++i) {
      dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
    }

    return max(*max_element(dp1.cbegin(), dp1.cend()), dp2.back());
  }
};
// @lc code=end
