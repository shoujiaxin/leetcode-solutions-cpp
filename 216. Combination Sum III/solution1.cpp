/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    1156
 * Dislikes: 53
 * Total Accepted:    173.4K
 * Total Submissions: 304.9K
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    backtrack(k, n, path, 0);
    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(int k, int target, vector<int>& path, int begin) {
    if (target == 0 && path.size() == k) {
      res.push_back(path);
      return;
    }

    for (auto i = begin + 1; i < 10; ++i) {
      if (target - i < 0) {
        break;
      }

      path.push_back(i);
      backtrack(k, target - i, path, i);
      path.pop_back();
    }
  }
};
// @lc code=end
