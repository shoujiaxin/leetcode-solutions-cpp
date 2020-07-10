/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    1512
 * Dislikes: 45
 * Total Accepted:    67.8K
 * Total Submissions: 124.8K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * Your are given an array of integers prices, for which the i-th element is
 * the price of a given stock on day i; and a non-negative integer fee
 * representing a transaction fee.
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.  You may not buy more than 1 share of
 * a stock at a time (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 *
 * Example 1:
 *
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] =
 * 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) =
 * 8.
 *
 *
 *
 * Note:
 * 0 < prices.length .
 * 0 < prices[i] < 50000.
 * 0 .
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    if (prices.empty()) {
      return 0;
    }

    auto n = prices.size();

    // dp[i][0] 表示第 i 天没有股票的最大利润
    // dp[i][1] 表示第 i 天持有股票的最大利润
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = -prices[0] - fee;

    for (auto i = 1; i <= n; ++i) {
      // 第 i 天没有股票：第 i - 1 天没有股票或第 i 天卖出股票
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
      // 第 i 天持有股票：第 i - 1 天持有股票或第 i 天买入股票
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1] - fee);
    }

    return dp[n][0];
  }
};
// @lc code=end
