/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (45.67%)
 * Likes:    755
 * Dislikes: 116
 * Total Accepted:    48.8K
 * Total Submissions: 105.4K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 *
 *
 *
 * Example:
 *
 *
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 *
 *
 *
 * Constraints:
 *
 *
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> path;
    backtrack(nums, path, 0);

    return {res.cbegin(), res.cend()};
  }

 private:
  set<vector<int>> res;

  void backtrack(const vector<int>& nums, vector<int> path, int depth) {
    if (path.size() > 1) {
      res.insert(path);
    }

    for (auto i = depth; i < nums.size(); ++i) {
      if (!path.empty() && nums[i] < path.back()) {
        continue;
      }

      path.push_back(nums[i]);

      backtrack(nums, path, i + 1);

      path.pop_back();
    }
  }
};
// @lc code=end
