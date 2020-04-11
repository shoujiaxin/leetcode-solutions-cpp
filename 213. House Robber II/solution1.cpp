/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (36.07%)
 * Likes:    1431
 * Dislikes: 45
 * Total Accepted:    156.4K
 * Total Submissions: 433.6K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    auto len = nums.size();
    if (len == 0) {
      return 0;
    } else if (len == 1) {
      return nums.front();
    }

    // 抢第一个房子，则不能抢最后一个房子
    auto robFirst = singleRob(nums.cbegin(), nums.cend() - 1);
    // 抢最后一个房子，则不能抢第一个房子
    auto robLast = singleRob(nums.cbegin() + 1, nums.cend());

    return max(robFirst, robLast);
  }

 private:
  // 同 198. House Robber，单排排列，非环状
  template <typename It>
  int singleRob(It first, It last) {
    auto pre = 0;
    auto cur = 0;

    for (auto it = first; it != last; ++it) {
      auto temp = cur;
      cur = max(pre + *it, cur);
      pre = temp;
    }

    return cur;
  }
};
// @lc code=end
