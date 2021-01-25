/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 *
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (46.59%)
 * Likes:    279
 * Dislikes: 139
 * Total Accepted:    30.9K
 * Total Submissions: 66.4K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j]
 * = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that
 * is, one domino can be rotated to be equal to another domino.
 *
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
 * and dominoes[i] is equivalent to dominoes[j].
 *
 *
 * Example 1:
 * Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 *
 */

// @lc code=start
class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<int, int> cnt;

    for (const auto& domino : dominoes) {
      auto a = min(domino.front(), domino.back());
      auto b = max(domino.front(), domino.back());
      ++cnt[10 * a + b];
    }

    auto res = 0;
    for (const auto& p : cnt) {
      if (p.second > 1) {
        res += p.second * (p.second - 1) / 2;
      }
    }

    return res;
  }
};
// @lc code=end
