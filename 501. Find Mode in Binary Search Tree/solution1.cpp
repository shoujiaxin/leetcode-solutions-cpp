/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (42.03%)
 * Likes:    991
 * Dislikes: 366
 * Total Accepted:    91.7K
 * Total Submissions: 215K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * For example:
 * Given BST [1,null,2,2],
 *
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 *
 *
 *
 *
 * return [2].
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
  vector<int> findMode(TreeNode* root) {
    dfs(root);

    vector<pair<int, int>> temp{cnt.cbegin(), cnt.cend()};
    sort(temp.begin(), temp.end(),
         [](const auto& p1, const auto& p2) { return p1.second > p2.second; });

    vector<int> res;
    for (const auto& p : temp) {
      if (p.second == temp.cbegin()->second) {
        res.push_back(p.first);
      } else {
        break;
      }
    }

    return res;
  }

 private:
  unordered_map<int, int> cnt;

  void dfs(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    ++cnt[root->val];

    dfs(root->left);
    dfs(root->right);
  }
};
// @lc code=end
