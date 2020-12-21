/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (50.73%)
 * Likes:    2624
 * Dislikes: 576
 * Total Accepted:    198.8K
 * Total Submissions: 391.6K
 * Testcase Example:  '[0,0,0,0]'
 *
 *
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 *
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 *
 *
 * Example 1:
 *
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 *
 *
 *
 * Example 2:
 *
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 *
 *
 *
 * Note:
 *
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    auto n = cost.size();
    auto dp = vector<int>(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (auto i = 2; i < n; ++i) {
      dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
  }
};
// @lc code=end
