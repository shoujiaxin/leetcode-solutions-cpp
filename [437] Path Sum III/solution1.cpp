/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (45.15%)
 * Likes:    2954
 * Dislikes: 232
 * Total Accepted:    163K
 * Total Submissions: 360.4K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
  int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
      return 0;
    }

    dfs(root, sum);
    if (root->left) {
      pathSum(root->left, sum);
    }
    if (root->right) {
      pathSum(root->right, sum);
    }

    return res;
  }

 private:
  int res;

  void dfs(TreeNode* node, int sum) {
    if (node == nullptr) {
      return;
    }

    if (node->val == sum) {
      ++res;
    }

    dfs(node->left, sum - node->val);
    dfs(node->right, sum - node->val);
  }
};
// @lc code=end
