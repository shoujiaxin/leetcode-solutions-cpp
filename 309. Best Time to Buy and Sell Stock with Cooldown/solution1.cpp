/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (46.28%)
 * Likes:    2319
 * Dislikes: 81
 * Total Accepted:    136.8K
 * Total Submissions: 295.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 *
 *
 * Example:
 *
 *
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    auto n = prices.size();

    // dp[i][0] 表示第 i 天没有股票的最大利润
    // dp[i][1] 表示第 i 天持有股票的最大利润
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = -prices[0];

    for (auto i = 1; i <= n; ++i) {
      // 第 i 天没有股票：第 i - 1 天没有股票或第 i 天卖出股票
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
      // 第 i 天持有股票：第 i - 1 天持有股票或第 i 天买入股票
      if (i >= 2) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
      } else {
        dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
      }
    }

    return dp[n][0];
  }
};
// @lc code=end
