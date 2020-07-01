/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (49.90%)
 * Likes:    5038
 * Dislikes: 221
 * Total Accepted:    863.9K
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

    auto minCost = prices.front();  // 前 i 天最低买入价格
    vector<int> dp(prices.size(), 0);  // dp[i] 表示第 i 天卖出的最大利润

    for (auto i = 1; i < prices.size(); ++i) {
      minCost = min(minCost, prices[i]);
      dp[i] = max(dp[i - 1], prices[i] - minCost);
    }

    return *max_element(dp.cbegin(), dp.cend());
  }
};
// @lc code=end
