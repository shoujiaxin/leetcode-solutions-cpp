/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (54.96%)
 * Likes:    2061
 * Dislikes: 122
 * Total Accepted:    126.6K
 * Total Submissions: 227.2K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 * Example:
 *
 *
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 *
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 *
 *
 * Note: This question is the same as 1038:
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
  TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }

    convertBST(root->right);

    sum += root->val;
    root->val = sum;

    convertBST(root->left);

    return root;
  }

 private:
  int sum;
};
// @lc code=end
