/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (64.46%)
 * Likes:    2104
 * Dislikes: 85
 * Total Accepted:    196.6K
 * Total Submissions: 304.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3]
 * Output: [1,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree will be in the range [0, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
  vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }

    vector<int> res;
    while (!q.empty()) {
      const auto n = q.size();
      auto cur = INT_MIN;
      for (auto i = 0; i < n; ++i) {
        const auto node = q.front();
        q.pop();

        cur = max(cur, node->val);

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      res.emplace_back(cur);
    }
    return res;
  }
};
// @lc code=end
