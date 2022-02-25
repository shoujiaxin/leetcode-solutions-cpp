/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (50.16%)
 * Likes:    1075
 * Dislikes: 195
 * Total Accepted:    283.3K
 * Total Submissions: 564.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) {
      return {};
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<vector<int>> res;

    while (!q.empty()) {
      vector<int> level;
      auto len = q.size();

      for (auto i = 0; i < len; ++i) {
        auto node = q.front();
        q.pop();

        level.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }

      res.push_back(level);
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
// @lc code=end
