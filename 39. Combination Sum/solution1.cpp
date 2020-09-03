/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.52%)
 * Likes:    3110
 * Dislikes: 97
 * Total Accepted:    476K
 * Total Submissions: 887.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) {
      return res;
    }

    sort(candidates.begin(), candidates.end());

    vector<int> path;
    backtrack(candidates, target, path, 0);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(const vector<int>& candidates, int target, vector<int>& path,
                 int begin) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (auto i = begin; i < candidates.size(); ++i) {
      if (target - candidates[i] < 0) {
        break;  // 剪枝（需排序）
      }

      path.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], path, i);
      path.pop_back();
    }
  }
};
// @lc code=end
