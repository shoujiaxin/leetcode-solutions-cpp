/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (37.09%)
 * Likes:    2071
 * Dislikes: 73
 * Total Accepted:    211.4K
 * Total Submissions: 569.4K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
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
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    auto n = prices.size();
    auto maxK = 2;

    // dp[i][k][0] 表示第 i 天交易 k 次且没有股票的最大利润
    // dp[i][k][1] 表示第 i 天交易 k 次且持有股票的最大利润
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(maxK + 1, vector<int>(2, 0)));
    for (auto i = 0; i <= n; ++i) {
      dp[i][0][1] = INT_MIN;
    }
    for (auto k = 0; k <= maxK; ++k) {
      dp[0][k][1] = INT_MIN;
    }

    for (auto i = 1; i <= n; ++i) {
      for (auto k = maxK; k >= 1; --k) {
        // 第 i 天没有股票：第 i - 1 天没有股票或第 i 天卖出股票
        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i - 1]);
        // 第 i 天持有股票：第 i - 1 天持有股票或第 i 天买入股票
        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i - 1]);
      }
    }

    return dp[n][maxK][0];
  }
};
// @lc code=end
