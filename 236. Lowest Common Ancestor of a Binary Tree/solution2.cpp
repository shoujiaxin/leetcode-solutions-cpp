/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (42.79%)
 * Likes:    3037
 * Dislikes: 162
 * Total Accepted:    403.2K
 * Total Submissions: 939.2K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 *
 *
 * Note:
 *
 *
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    vector<TreeNode*> pathToP;
    getPath(root, p->val, pathToP);

    vector<TreeNode*> pathToQ;
    getPath(root, q->val, pathToQ);

    auto minLen = min(pathToP.size(), pathToQ.size());
    auto i = 0;
    while (i < minLen) {
      if (pathToP[i] != pathToQ[i]) {
        break;
      }
      ++i;
    }

    return pathToP[--i];
  }

 private:
  /// 回溯法获取二叉树根节点到给定节点的路径
  /// @param node 当前节点
  /// @param target 目标节点的值
  /// @param path 当前路径
  bool getPath(TreeNode* node, int target, vector<TreeNode*>& path) {
    path.push_back(node);
    if (node->val == target) {
      return true;
    }

    if (node->left && getPath(node->left, target, path)) {
      return true;
    }
    if (node->right && getPath(node->right, target, path)) {
      return true;
    }

    path.pop_back();
    return false;
  }
};
// @lc code=end
