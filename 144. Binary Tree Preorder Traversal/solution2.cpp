/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (54.10%)
 * Likes:    1252
 * Dislikes: 53
 * Total Accepted:    449.9K
 * Total Submissions: 828.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,2,3]
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> stk;
    auto node = root;

    while (node || !stk.empty()) {
      while (node) {
        res.push_back(node->val);

        stk.push(node);
        node = node->left;
      }

      if (!stk.empty()) {
        node = stk.top();
        stk.pop();

        node = node->right;
      }
    }

    return res;
  }
};
// @lc code=end
