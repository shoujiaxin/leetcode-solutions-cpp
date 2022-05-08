/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.16%)
 * Likes:    6893
 * Dislikes: 159
 * Total Accepted:    384K
 * Total Submissions: 571.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    const int n = temperatures.size();
    stack<int> stk;
    vector<int> res(n, 0);

    for (auto i = n - 1; i >= 0; --i) {
      while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
        stk.pop();
      }
      if (!stk.empty()) {
        res[i] = stk.top() - i;
      }
      stk.push(i);
    }

    return res;
  }
};
// @lc code=end
