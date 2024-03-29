/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (52.17%)
 * Likes:    1845
 * Dislikes: 106
 * Total Accepted:    252.9K
 * Total Submissions: 483K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;

    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }

    while (!q.empty()) {
      TreeNode* node;

      const auto n = q.size();
      for (auto i = 0; i < n; ++i) {
        node = q.front();
        q.pop();

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }

      res.push_back(node->val);
    }

    return res;
  }
};
// @lc code=end
