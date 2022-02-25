/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.41%)
 * Likes:    1607
 * Dislikes: 85
 * Total Accepted:    311.4K
 * Total Submissions: 685.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<vector<int>> res;
    auto curLevel = 0;

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

      if (curLevel % 2) {
        reverse(level.begin(), level.end());
      }
      res.push_back(level);
      ++curLevel;
    }

    return res;
  }
};
// @lc code=end
