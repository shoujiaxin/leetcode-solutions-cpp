/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (49.31%)
 * Likes:    1737
 * Dislikes: 344
 * Total Accepted:    242.5K
 * Total Submissions: 467.5K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,3,2]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    array<int, 32> bitCnt{0};

    for (auto n : nums) {
      for (auto i = 0; i < 32; ++i) {
        bitCnt[i] += n & 1;
        n >>= 1;
      }
    }

    auto res = 0;
    for (auto i = 31; i >= 0; --i) {
      res <<= 1;
      res += bitCnt[i] % 3;
    }

    return res;
  }
};
// @lc code=end
