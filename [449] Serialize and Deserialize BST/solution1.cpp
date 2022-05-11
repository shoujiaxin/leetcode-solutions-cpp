/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (56.20%)
 * Likes:    2670
 * Dislikes: 133
 * Total Accepted:    193.6K
 * Total Submissions: 344.2K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is converting a data structure or object into a sequence of
 * bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or
 * another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You need to ensure that a binary search tree can be serialized to a
 * string, and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 * Example 2:
 * Input: root = []
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The input tree is guaranteed to be a binary search tree.
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
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }

    auto str = to_string(root->val) + " ";
    str += serialize(root->left);
    str += serialize(root->right);
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }

    vector<int> preorder;
    istringstream in(data);
    string num;
    while (in >> num) {
      preorder.emplace_back(stoi(num));
    }

    vector<int> inorder = preorder;
    quickSort(inorder.begin(), inorder.end());

    return buildTree(preorder, inorder);
  }

 private:
  // 快速排序
  template <typename It>
  void quickSort(It first, It last) {
    if (last - first <= 1) {
      return;
    }

    const auto pivot = *first;
    auto i = first;
    auto j = last - 1;
    while (i < j) {
      while (i < j && *j >= pivot) {
        --j;
      }
      *i = *j;
      while (i < j && *i <= pivot) {
        ++i;
      }
      *j = *i;
    }
    *i = pivot;

    quickSort(first, i);
    quickSort(i + 1, last);
  }

  TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) {
      return nullptr;
    }

    const auto rootVal = preorder.front();
    const auto root = new TreeNode(rootVal);

    // 二分查找
    int l = 0;
    int r = inorder.size() - 1;
    while (l < r) {
      const auto m = l + (r - l) / 2;
      if (inorder[m] < rootVal) {
        ++l;
      } else if (inorder[m] > rootVal) {
        --r;
      } else {
        l = m;
        break;
      }
    }

    vector<int> leftPreorder(preorder.cbegin() + 1, preorder.cbegin() + l + 1);
    vector<int> leftInorder(inorder.cbegin(), inorder.cbegin() + l);
    root->left = buildTree(leftPreorder, leftInorder);

    vector<int> rightPreorder(preorder.cbegin() + l + 1, preorder.cend());
    vector<int> rightInorder(inorder.cbegin() + l + 1, inorder.cend());
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
