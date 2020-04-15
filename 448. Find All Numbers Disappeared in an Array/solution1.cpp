/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (55.37%)
 * Likes:    2443
 * Dislikes: 223
 * Total Accepted:    223.8K
 * Total Submissions: 404.1K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (const auto& n : nums) {
      ++cnt[n];
    }

    vector<int> res;
    for (auto i = 1; i <= nums.size(); ++i) {
      if (cnt[i] == 0) {
        res.push_back(i);
      }
    }

    return res;
  }
};
// @lc code=end
