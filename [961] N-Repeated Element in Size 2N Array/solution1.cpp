/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 *
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (75.47%)
 * Likes:    897
 * Dislikes: 294
 * Total Accepted:    177.4K
 * Total Submissions: 234.9K
 * Testcase Example:  '[1,2,3,3]'
 *
 * You are given an integer array nums with the following properties:
 *
 *
 * nums.length == 2 * n.
 * nums contains n + 1 unique elements.
 * Exactly one element of nums is repeated n times.
 *
 *
 * Return the element that is repeated n times.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,1,2,5,3,2]
 * Output: 2
 * Example 3:
 * Input: nums = [5,1,5,2,5,3,5,4]
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 5000
 * nums.length == 2 * n
 * 0 <= nums[i] <= 10^4
 * nums contains n + 1 unique elements and one of them is repeated exactly n
 * times.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_set<int> s;
    for (const auto& n : nums) {
      if (s.count(n)) {
        return n;
      }
      s.insert(n);
    }
    return -1;
  }
};
// @lc code=end
