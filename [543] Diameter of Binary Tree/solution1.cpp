/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.60%)
 * Likes:    2230
 * Dislikes: 141
 * Total Accepted:    214.5K
 * Total Submissions: 444.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
  int diameterOfBinaryTree(TreeNode* root) {
    depth(root);

    return maxLength;
  }

  int depth(TreeNode* node) {
    if (!node) {
      return 0;
    }

    auto leftDepth = depth(node->left);
    auto rightDepth = depth(node->right);

    maxLength = std::max(leftDepth + rightDepth, maxLength);

    return std::max(leftDepth, rightDepth) + 1;
  }

 private:
  int maxLength = 0;
};
// @lc code=end
