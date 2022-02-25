/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.75%)
 * Likes:    3239
 * Dislikes: 125
 * Total Accepted:    591.7K
 * Total Submissions: 948.6K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,1]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    std::map<int, int> numCount;

    for (const auto& num : nums) {
      numCount[num]++;
    }

    for (const auto& cnt : numCount) {
      if (cnt.second == 1) {
        return cnt.first;
      }
    }

    return 0;
  }
};
// @lc code=end
