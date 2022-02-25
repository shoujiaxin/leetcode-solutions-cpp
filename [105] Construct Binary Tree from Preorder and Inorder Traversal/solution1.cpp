/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.68%)
 * Likes:    2667
 * Dislikes: 78
 * Total Accepted:    309K
 * Total Submissions: 671.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
      return nullptr;
    }

    // 前序遍历序列的第一个元素为根节点
    auto rootVal = preorder.front();
    auto root = new TreeNode(rootVal);

    // 查找根节点在中序遍历序列中的位置
    auto it = find(inorder.cbegin(), inorder.cend(), rootVal);

    // 递归构建左子树
    vector<int> leftPreorder(preorder.cbegin() + 1,
                             preorder.cbegin() + 1 + (it - inorder.cbegin()));
    vector<int> leftInorder(inorder.cbegin(), it);
    root->left = buildTree(leftPreorder, leftInorder);

    // 递归构建右子树
    vector<int> rightPreorder(preorder.cbegin() + 1 + (it - inorder.cbegin()),
                              preorder.cend());
    vector<int> rightInorder(it + 1, inorder.cend());
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
  }
};
// @lc code=end
