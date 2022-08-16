/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 *
 * https://leetcode.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (87.02%)
 * Likes:    3539
 * Dislikes: 96
 * Total Accepted:    234.3K
 * Total Submissions: 269.3K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * Given the root of a binary tree, return the sum of values of its deepest
 * leaves.
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 19
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 1 <= Node.val <= 100
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
  int deepestLeavesSum(TreeNode* root) {
    std::queue<TreeNode*> que;
    if (root) {
      que.push(root);
    }

    auto sum = 0;
    while (!que.empty()) {
      const auto n = que.size();
      sum = 0;
      for (auto i = 0; i < n; ++i) {
        const auto node = que.front();
        que.pop();

        sum += node->val;

        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
    }

    return sum;
  }
};
// @lc code=end
