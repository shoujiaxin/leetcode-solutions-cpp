/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (44.50%)
 * Likes:    1398
 * Dislikes: 47
 * Total Accepted:    298.9K
 * Total Submissions: 670.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 *
 *
 * Return:
 *
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
      return res;
    }

    vector<int> path;
    backtrack(root, sum, path);

    return res;
  }

 private:
  vector<vector<int>> res;

  void backtrack(TreeNode* node, int sum, vector<int>& path) {
    if (node == nullptr) {
      return;
    }

    path.push_back(node->val);
    sum -= node->val;

    if (node->left == nullptr && node->right == nullptr && sum == 0) {
      res.push_back(path);
      path.pop_back();
      return;
    }

    backtrack(node->left, sum, path);
    backtrack(node->right, sum, path);

    path.pop_back();
  }
};
// @lc code=end
