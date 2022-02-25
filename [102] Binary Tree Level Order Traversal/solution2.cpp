/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.40%)
 * Likes:    2380
 * Dislikes: 62
 * Total Accepted:    531.4K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> res;
    vector<int> nodes;

    queue<pair<TreeNode*, int>> q;
    auto curLevel = 0;  // 当前访问节点的层数
    q.push({root, curLevel});

    while (!q.empty()) {
      auto node = q.front().first;
      auto level = q.front().second;
      q.pop();

      if (curLevel == level) {
        nodes.push_back(node->val);
      } else {
        curLevel = level;
        res.push_back(nodes);
        nodes.clear();
        nodes.push_back(node->val);
      }

      if (node->left) {
        q.push({node->left, level + 1});
      }
      if (node->right) {
        q.push({node->right, level + 1});
      }
    }
    res.push_back(nodes);

    return res;
  }
};
// @lc code=end
