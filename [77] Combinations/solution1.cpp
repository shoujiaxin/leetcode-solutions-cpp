/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (52.29%)
 * Likes:    1215
 * Dislikes: 61
 * Total Accepted:    264.2K
 * Total Submissions: 503K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    backtrack(n, k, path, 1);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(int n, int k, vector<int> &path, int begin) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }

    for (auto i = begin; i <= n; ++i) {
      path.push_back(i);

      backtrack(n, k, path, i + 1);

      path.pop_back();
    }
  }
};
// @lc code=end
