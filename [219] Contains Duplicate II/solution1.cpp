/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (36.97%)
 * Likes:    734
 * Dislikes: 891
 * Total Accepted:    250.5K
 * Total Submissions: 677.3K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;

    for (auto i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
        return true;
      }

      m[nums[i]] = i;
    }

    return false;
  }
};
// @lc code=end
