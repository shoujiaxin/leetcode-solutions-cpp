/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (53.46%)
 * Likes:    985
 * Dislikes: 73
 * Total Accepted:    97K
 * Total Submissions: 179.3K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 *
 *
 *
 *
 * Note:
 *
 *
 * There are at least two nodes in this BST.
 * This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
  int getMinimumDifference(TreeNode* root) {
    dfs(root);

    auto res = INT_MAX;
    for (auto it = nums.cbegin() + 1; it < nums.cend(); ++it) {
      res = min(res, *it - *(it - 1));
    }

    return res;
  }

 private:
  vector<int> nums;

  void dfs(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    dfs(root->left);
    nums.push_back(root->val);
    dfs(root->right);
  }
};
// @lc code=end
