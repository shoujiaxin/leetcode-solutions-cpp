/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (56.52%)
 * Likes:    2428
 * Dislikes: 1754
 * Total Accepted:    611.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array prices for which the i^th element is the price of a
 * given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 *
 *
 * Example 3:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 3 * 10 ^ 4
 * 0 <= prices[i] <= 10 ^ 4
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
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
    }

    return dp[n][0];
  }
};
// @lc code=end
