/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (62.85%)
 * Likes:    1561
 * Dislikes: 235
 * Total Accepted:    110.6K
 * Total Submissions: 175K
 * Testcase Example:  '[5,2,-3]'
 *
 * Given the root of a binary tree, return the most frequent subtree sum. If
 * there is a tie, return all the values with the highest frequency in any
 * order.
 *
 * The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,2,-3]
 * Output: [2,-3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,2,-5]
 * Output: [2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    dfs(root);

    auto maxCnt = 0;
    for (const auto& p : sums) {
      maxCnt = max(maxCnt, p.second);
    }

    vector<int> res;
    for (const auto& p : sums) {
      if (p.second == maxCnt) {
        res.push_back(p.first);
      }
    }
    return res;
  }

 private:
  unordered_map<int, int> sums;

  int dfs(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    const auto l = dfs(root->left);
    const auto r = dfs(root->right);
    const auto sum = l + r + root->val;
    ++sums[sum];
    return sum;
  }
};
// @lc code=end
