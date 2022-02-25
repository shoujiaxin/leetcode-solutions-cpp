/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (49.51%)
 * Likes:    4196
 * Dislikes: 192
 * Total Accepted:    753.4K
 * Total Submissions: 1.5M
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
    // 转换为求连续子数组的最大和问题
    auto sum = 0;
    auto profit = 0;
    for (auto i = 1; i < prices.size(); ++i) {
      if (sum > 0) {
        sum += prices[i] - prices[i - 1];
      } else {
        sum = prices[i] - prices[i - 1];
      }

      profit = max(profit, sum);
    }

    return profit;
  }
};
// @lc code=end
