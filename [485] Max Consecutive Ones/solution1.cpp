/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.21%)
 * Likes:    539
 * Dislikes: 349
 * Total Accepted:    183.9K
 * Total Submissions: 327.4K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 *
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 *
 *
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    auto len = 0;
    auto maxLen = 0;

    for (const auto& n : nums) {
      if (n == 1) {
        ++len;
      } else {
        maxLen = max(maxLen, len);
        len = 0;
      }
    }

    return max(maxLen, len);
  }
};
// @lc code=end
