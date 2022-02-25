/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (30.15%)
 * Likes:    564
 * Dislikes: 1049
 * Total Accepted:    129.6K
 * Total Submissions: 429K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 *
 * Example 1:
 *
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 *
 *
 *
 * Example 3:
 *
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    auto low = LONG_MIN;
    auto mid = LONG_MIN;
    auto high = LONG_MIN;

    for (const auto& n : nums) {
      if (n > high) {
        low = mid;
        mid = high;
        high = n;
      } else if (n < high && n > mid) {
        low = mid;
        mid = n;
      } else if (n < mid && n > low) {
        low = n;
      }
    }

    return low == LONG_MIN ? high : low;
  }
};
// @lc code=end
