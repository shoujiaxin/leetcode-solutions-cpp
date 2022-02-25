/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 *
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (78.19%)
 * Likes:    1026
 * Dislikes: 83
 * Total Accepted:    122.3K
 * Total Submissions: 158.6K
 * Testcase Example:  '[4,2,7,1,3]\n5'
 *
 * Given the root node of a binary search tree (BST) and a value to be inserted
 * into the tree, insert the value into the BST. Return the root node of the
 * BST after the insertion. It is guaranteed that the new value does not exist
 * in the original BST.
 *
 * Note that there may exist multiple valid ways for the insertion, as long as
 * the tree remains a BST after insertion. You can return any of them.
 *
 * For example, 
 *
 *
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * And the value to insert: 5
 *
 *
 * You can return this binary search tree:
 *
 *
 * ⁠        4
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \   /
 * ⁠   1   3 5
 *
 *
 * This tree is also valid:
 *
 *
 * ⁠        5
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \
 * ⁠   1   3
 * ⁠        \
 * ⁠         4
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the given tree will be between 0 and 10^4.
 * Each node will have a unique integer value from 0 to -10^8, inclusive.
 * -10^8 <= val <= 10^8
 * It's guaranteed that val does not exist in the original BST.
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    auto p = root;
    while (p) {
      if (val < p->val) {
        if (p->left) {
          p = p->left;
        } else {
          p->left = new TreeNode(val);
          break;
        }
      } else {
        if (p->right) {
          p = p->right;
        } else {
          p->right = new TreeNode(val);
          break;
        }
      }
    }

    return root;
  }
};
// @lc code=end
