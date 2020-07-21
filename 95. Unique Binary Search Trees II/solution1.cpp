/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (40.15%)
 * Likes:    2221
 * Dislikes: 159
 * Total Accepted:    193.3K
 * Total Submissions: 479K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 8
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      return {};
    }

    return generateTrees(1, n);
  }

 private:
  vector<TreeNode*> generateTrees(int begin, int end) {
    if (begin > end) {
      return {nullptr};
    }

    vector<TreeNode*> res;

    for (auto i = begin; i <= end; ++i) {
      auto leftTrees = generateTrees(begin, i - 1);
      auto rightTrees = generateTrees(i + 1, end);

      for (const auto& left : leftTrees) {
        for (const auto& right : rightTrees) {
          auto root = new TreeNode(i, left, right);
          res.push_back(root);
        }
      }
    }

    return res;
  }
};
// @lc code=end
