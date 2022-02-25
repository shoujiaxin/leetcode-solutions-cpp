/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (41.96%)
 * Likes:    894
 * Dislikes: 129
 * Total Accepted:    93.7K
 * Total Submissions: 223.1K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 *
 * Example 1:
 *
 *
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    auto left = nums.cbegin();
    auto right = left + k;
    auto sum = accumulate(left, right, 0);
    auto maxSum = sum;

    while (right < nums.cend()) {
      sum += *right - *left;
      ++left;
      ++right;
      maxSum = max(maxSum, sum);
    }

    return static_cast<double>(maxSum) / k;
  }
};
// @lc code=end
