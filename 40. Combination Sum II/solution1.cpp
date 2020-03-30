/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (45.80%)
 * Likes:    1409
 * Dislikes: 55
 * Total Accepted:    294.6K
 * Total Submissions: 640.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.empty()) {
      return res;
    }

    sort(candidates.begin(), candidates.end());
    vector<int> path;

    backtrack(candidates, path, target, 0);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(const vector<int>& candidates, vector<int>& path, int target,
                 int begin) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (auto i = begin; i < candidates.size(); ++i) {
      if (target - candidates[i] < 0) {
        return;  // 剪枝
      }
      if (i > begin && candidates[i] == candidates[i - 1]) {
        continue;  // 去除重复结果
      }

      path.push_back(candidates[i]);

      backtrack(candidates, path, target - candidates[i], i + 1);

      path.pop_back();
    }
  }
};
// @lc code=end
