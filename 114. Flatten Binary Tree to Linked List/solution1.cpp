/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    2783
 * Dislikes: 332
 * Total Accepted:    346.8K
 * Total Submissions: 710.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 *
 *
 * The flattened tree should look like:
 *
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
  void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    vector<TreeNode*> nodes;

    stack<TreeNode*> stk;
    auto node = root;

    while (node || !stk.empty()) {
      while (node) {
        nodes.push_back(node);

        stk.push(node);
        node = node->left;
      }

      if (!stk.empty()) {
        node = stk.top();
        stk.pop();

        node = node->right;
      }
    }

    for (auto i = 0; i < nodes.size() - 1; ++i) {
      nodes[i]->left = nullptr;
      nodes[i]->right = nodes[i + 1];
    }
  }
};
// @lc code=end
