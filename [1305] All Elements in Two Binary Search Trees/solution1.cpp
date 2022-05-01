/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (79.61%)
 * Likes:    2211
 * Dislikes: 65
 * Total Accepted:    161.2K
 * Total Submissions: 202.5K
 * Testcase Example:  '[2,1,4]\n[1,0,3]'
 *
 * Given two binary search trees root1 and root2, return a list containing all
 * the integers from both trees sorted in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree is in the range [0, 5000].
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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> nums;
    const auto& inorder = [&](TreeNode* root) {
      stack<TreeNode*> stk;
      auto node = root;
      while (node || !stk.empty()) {
        while (node) {
          stk.push(node);
          node = node->left;
        }
        if (!stk.empty()) {
          node = stk.top();
          stk.pop();
          nums.push_back(node->val);
          node = node->right;
        }
      }
    };

    inorder(root1);
    const auto len1 = nums.size();
    inorder(root2);
    const auto len2 = nums.size() - len1;

    // merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
    //       back_inserter(res));
    merge(nums, 0, len1, len1 + len2);
    return nums;
  }

 private:
  void merge(vector<int>& nums, int begin, int mid, int end) {
    while (begin < mid && mid < end) {
      while (begin < mid && nums[begin] < nums[mid]) {
        ++begin;
      }
      const auto i = mid;
      while (mid < end && nums[mid] < nums[begin]) {
        ++mid;
      }

      reverse(nums.begin() + begin, nums.begin() + i);
      reverse(nums.begin() + i, nums.begin() + mid);
      reverse(nums.begin() + begin, nums.begin() + mid);

      begin += mid - i + 1;
    }
  }
};
// @lc code=end
