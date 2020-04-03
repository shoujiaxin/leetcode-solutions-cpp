/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.62%)
 * Likes:    1878
 * Dislikes: 149
 * Total Accepted:    412K
 * Total Submissions: 964.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 *
 * Example 1:
 *
 * Given the following tree [3,9,20,null,null,15,7]:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * Return true.
 *
 * Example 2:
 *
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 *
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 *
 *
 * Return false.
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
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }

    return abs(height(root->left) - height(root->right)) < 2 &&
           isBalanced(root->left) && isBalanced(root->right);
  }

 private:
  int height(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    return max(height(node->left), height(node->right)) + 1;
  }
};
// @lc code=end
