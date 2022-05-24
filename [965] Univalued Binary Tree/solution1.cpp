/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * https://leetcode.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (68.99%)
 * Likes:    1298
 * Dislikes: 56
 * Total Accepted:    161K
 * Total Submissions: 233.5K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * A binary tree is uni-valued if every node in the tree has the same value.
 *
 * Given the root of a binary tree, return true if the given tree is
 * uni-valued, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,1,1,1,1,null,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,2,2,5,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 100].
 * 0 <= Node.val < 100
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
  bool isUnivalTree(TreeNode* root) { return dfs(root, root->val); }

 private:
  bool dfs(TreeNode* root, int val) {
    if (root == nullptr) {
      return true;
    }

    return root->val == val && dfs(root->left, val) && dfs(root->right, val);
  }
};
// @lc code=end
