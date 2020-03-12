/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.40%)
 * Likes:    3010
 * Dislikes: 102
 * Total Accepted:    629.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Note:
 *
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 */

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    auto curr = nums.begin();

    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
      if (*it != 0) {
        *curr = *it;
        ++curr;
      }
    }

    while (curr != nums.end()) {
      *curr = 0;
      ++curr;
    }
  }
};
// @lc code=end
