/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    1340
 * Dislikes: 29
 * Total Accepted:    197.8K
 * Total Submissions: 453.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.empty()) {
      return nullptr;
    }

    // 后序遍历的最后一个元素为根节点
    auto rootVal = postorder.back();
    auto root = new TreeNode(rootVal);

    // 查找根节点在中序遍历序列中的位置
    auto it = find(inorder.cbegin(), inorder.cend(), rootVal);

    // 递归构建左子树
    vector<int> leftInorder(inorder.cbegin(), it);
    vector<int> leftPostorder(postorder.cbegin(),
                              postorder.cbegin() + (it - inorder.cbegin()));
    root->left = buildTree(leftInorder, leftPostorder);

    // 递归构建右子树
    vector<int> rightInorder(it + 1, inorder.cend());
    vector<int> rightPostorder(postorder.cbegin() + (it - inorder.cbegin()),
                               postorder.cend() - 1);
    root->right = buildTree(rightInorder, rightPostorder);

    return root;
  }
};
// @lc code=end
