/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (27.83%)
 * Likes:    1438
 * Dislikes: 91
 * Total Accepted:    127.6K
 * Total Submissions: 458.2K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(int maxK, vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    auto n = prices.size();

    // 买入卖出各需要 1 天，故总交易次数不会超过天数的一半
    if (maxK > n / 2) {
      vector<vector<int>> dp(n + 1, vector<int>(2, 0));
      dp[0][1] = INT_MIN;

      for (auto i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
      }

      return dp[n][0];
    }

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
