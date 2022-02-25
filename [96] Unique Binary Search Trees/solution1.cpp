/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (52.40%)
 * Likes:    3408
 * Dislikes: 123
 * Total Accepted:    303.8K
 * Total Submissions: 578.4K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (auto i = 2; i <= n; ++i) {
      for (auto j = 1; j <= i; ++j) {
        // dp[j - 1] 表示左子树的个数
        // dp[i - j] 表示右子树的个数
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }

    return dp.back();
  }
};
// @lc code=end
