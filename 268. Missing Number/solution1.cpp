/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (50.61%)
 * Likes:    1476
 * Dislikes: 1856
 * Total Accepted:    404.4K
 * Total Submissions: 798.4K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Example 1:
 *
 *
 * Input: [3,0,1]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    auto sum = accumulate(nums.cbegin(), nums.cend(), 0);
    auto len = nums.size();

    return len * (len + 1) / 2 - sum;
  }
};
// @lc code=end
