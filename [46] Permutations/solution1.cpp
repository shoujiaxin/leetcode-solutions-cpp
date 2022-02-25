/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.58%)
 * Likes:    3233
 * Dislikes: 95
 * Total Accepted:    535.7K
 * Total Submissions: 880.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<int> path;
    backtrack(nums, used, path, 0);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path,
                 int depth) {
    if (depth == nums.size()) {
      res.push_back(path);
      return;
    }

    for (auto i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }

      used[i] = true;
      path.push_back(nums[i]);

      backtrack(nums, used, path, depth + 1);

      used[i] = false;
      path.pop_back();
    }
  }
};
// @lc code=end
