/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (50.38%)
 * Likes:    976
 * Dislikes: 110
 * Total Accepted:    162.7K
 * Total Submissions: 322.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    dfs(root);

    return res;
  }

 private:
  int res;

  void dfs(TreeNode* node) {
    if (node == nullptr) {
      return;
    }

    if (node->left && node->left->left == nullptr &&
        node->left->right == nullptr) {
      res += node->left->val;
    }

    dfs(node->left);
    dfs(node->right);
  }
};
// @lc code=end
