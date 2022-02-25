/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (52.60%)
 * Likes:    1445
 * Dislikes: 74
 * Total Accepted:    343.3K
 * Total Submissions: 648.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
  vector<int> postorderTraversal(TreeNode* root) {
    recur(root);
    return res;
  }

 private:
  vector<int> res;

  void recur(TreeNode* node) {
    if (node == nullptr) {
      return;
    }

    recur(node->left);
    recur(node->right);
    res.push_back(node->val);
  }
};
// @lc code=end
