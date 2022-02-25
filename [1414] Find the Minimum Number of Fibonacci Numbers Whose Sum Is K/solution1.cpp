/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 *
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/
 *
 * algorithms
 * Medium (65.07%)
 * Likes:    627
 * Dislikes: 51
 * Total Accepted:    29.5K
 * Total Submissions: 45.2K
 * Testcase Example:  '7'
 *
 * Given an integer k, return the minimum number of Fibonacci numbers whose sum
 * is equal to k. The same Fibonacci number can be used multiple times.
 *
 * The Fibonacci numbers are defined as:
 *
 *
 * F1 = 1
 * F2 = 1
 * Fn = Fn-1 + Fn-2 for n > 2.
 *
 * It is guaranteed that for the given constraints we can always find such
 * Fibonacci numbers that sum up to k.
 *
 * Example 1:
 *
 *
 * Input: k = 7
 * Output: 2
 * Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ...
 * For k = 7 we can use 2 + 5 = 7.
 *
 * Example 2:
 *
 *
 * Input: k = 10
 * Output: 2
 * Explanation: For k = 10 we can use 2 + 8 = 10.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 19
 * Output: 3
 * Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fibs{1, 1};
    while (fibs.back() < k) {
      fibs.emplace_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
    }

    auto cnt = 0;
    for (auto it = fibs.rbegin(); it < fibs.rend();) {
      if (k == 0) {
        break;
      } else if (k >= *it) {
        k -= *it;
        ++cnt;
      } else {
        ++it;
      }
    }
    return cnt;
  }
};
// @lc code=end
