/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.51%)
 * Likes:    2295
 * Dislikes: 192
 * Total Accepted:    483.7K
 * Total Submissions: 873.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */

// @lc code=start
// 投票
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int vote = 0;
    int candidate;

    for (const auto& n : nums) {
      if (vote == 0) {
        candidate = n;
      }

      vote += (n == candidate) ? 1 : -1;
    }

    return candidate;
  }
};
// @lc code=end
