/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (46.09%)
 * Likes:    2891
 * Dislikes: 141
 * Total Accepted:    317.6K
 * Total Submissions: 678.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream output;

    // 层序遍历
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      auto node = que.front();
      que.pop();

      if (node) {
        output << node->val << " ";
        que.push(node->left);
        que.push(node->right);
      } else {
        output << "null ";
      }
    }

    return output.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<TreeNode*> nodes;
    istringstream input(data);
    string val;
    while (input >> val) {
      if (val == "null") {
        nodes.push_back(nullptr);
      } else {
        nodes.push_back(new TreeNode(stoi(val)));
      }
    }

    auto j = 1;
    for (auto i = 0; i < nodes.size(); ++i) {
      if (nodes[i] == nullptr) {
        continue;
      }
      if (j < nodes.size()) {
        nodes[i]->left = nodes[j];
        ++j;
      }
      if (j < nodes.size()) {
        nodes[i]->right = nodes[j];
        ++j;
      }
    }

    return nodes.front();
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
