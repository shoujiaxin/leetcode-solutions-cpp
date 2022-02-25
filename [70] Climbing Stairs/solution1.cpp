/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (45.32%)
 * Likes:    2787
 * Dislikes: 98
 * Total Accepted:    495.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> steps;
    steps.push_back(1);
    steps.push_back(2);

    // Fibonacci number
    for (auto i = 2; i < n; ++i) {
      steps.push_back(steps[i - 2] + steps[i - 1]);
    }

    return steps[n - 1];
  }
};
// @lc code=end
