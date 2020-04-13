/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (49.57%)
 * Likes:    1405
 * Dislikes: 90
 * Total Accepted:    290K
 * Total Submissions: 584.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
  vector<string> binaryTreePaths(TreeNode* root) {
    dfs(root, "");
    return res;
  }

 private:
  vector<string> res;

  void dfs(TreeNode* node, string path) {
    if (node == nullptr) {
      return;
    }

    path += to_string(node->val);

    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(path);
    } else {
      path += "->";
      dfs(node->left, path);
      dfs(node->right, path);
    }
  }
};
// @lc code=end
