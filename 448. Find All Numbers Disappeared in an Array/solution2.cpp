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
    // 将下标为 abs(nums[i]) - 1 的元素标记为负
    for (const auto& n : nums) {
      auto index = abs(n) - 1;
      if (nums[index] > 0) {
        nums[index] *= -1;
      }
    }

    // nums[i] 为负，表示 i + 1 存在；否则不存在
    vector<int> res;
    for (auto i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }

    return res;
  }
};
// @lc code=end
