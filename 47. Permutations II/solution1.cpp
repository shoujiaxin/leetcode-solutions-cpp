/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    1625
 * Dislikes: 57
 * Total Accepted:    320.2K
 * Total Submissions: 717.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<int> path;
    backtrack(nums, used, path, 0);

    return vector<vector<int>>(res.begin(), res.end());
  }

 private:
  set<vector<int>> res;

  void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path,
                 int depth) {
    if (depth == nums.size()) {
      res.insert(path);
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
