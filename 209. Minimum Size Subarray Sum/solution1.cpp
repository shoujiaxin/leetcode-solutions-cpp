/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (37.22%)
 * Likes:    2283
 * Dislikes: 106
 * Total Accepted:    263.9K
 * Total Submissions: 699K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 *
 * Example: 
 *
 *
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 *
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    auto left = 0;
    auto right = 0;
    auto sum = 0;
    int len = nums.size();

    while (right < nums.size()) {
      if (sum < s) {
        sum += nums[right];
        ++right;
      } else {
        while (sum >= s) {
          len = min(len, right - left);

          sum -= nums[left];
          ++left;
        }
      }
    }

    if (left == 0 && right == nums.size() && sum < s) {
      return 0;  // nums 所有数之和小于 s
    }

    while (sum >= s) {
      len = min(len, right - left);

      sum -= nums[left];
      ++left;
    }

    return len;
  }
};
// @lc code=end
