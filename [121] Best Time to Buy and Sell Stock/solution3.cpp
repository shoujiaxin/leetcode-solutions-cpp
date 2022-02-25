/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (50.26%)
 * Likes:    5144
 * Dislikes: 225
 * Total Accepted:    875.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
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
      dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
    }

    return dp[n][0];
  }
};
// @lc code=end
