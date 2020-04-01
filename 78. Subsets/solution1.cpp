/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.19%)
 * Likes:    3047
 * Dislikes: 72
 * Total Accepted:    501.8K
 * Total Submissions: 857.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    backtrack(nums, path, 0);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(const vector<int>& nums, vector<int>& path, int begin) {
    res.push_back(path);

    for (auto i = begin; i < nums.size(); ++i) {
      path.push_back(nums[i]);

      backtrack(nums, path, i + 1);

      path.pop_back();
    }
  }
};
// @lc code=end
