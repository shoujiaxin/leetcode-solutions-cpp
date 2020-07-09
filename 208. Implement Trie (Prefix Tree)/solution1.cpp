/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    3164
 * Dislikes: 50
 * Total Accepted:    320.9K
 * Total Submissions: 660.2K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */

// @lc code=start
class TrieNode {
 public:
  bool contains(const char &ch) const { return _links[ch - 'a'] != nullptr; }

  void put(const char &ch, const std::shared_ptr<TrieNode> node) {
    _links[ch - 'a'] = node;
  }

  std::shared_ptr<TrieNode> get(const char &ch) const {
    return _links[ch - 'a'];
  };

  void set_end(const bool &end) { _is_end = end; }

  bool is_end() const { return _is_end; }

 private:
  std::array<std::shared_ptr<TrieNode>, 26> _links{nullptr};
  bool _is_end = false;
};

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() : _root(std::make_shared<TrieNode>()) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    auto node = _root;

    for (const auto &ch : word) {
      if (!node->contains(ch)) {
        node->put(ch, std::make_shared<TrieNode>());
      }
      node = node->get(ch);
    }

    node->set_end(true);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto node = search_prefix(word);
    return node != nullptr && node->is_end();
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto node = search_prefix(prefix);
    return node != nullptr;
  }

 private:
  std::shared_ptr<TrieNode> _root;

  std::shared_ptr<TrieNode> search_prefix(const std::string &prefix) const {
    auto node = _root;

    for (const auto &ch : prefix) {
      if (node->contains(ch)) {
        node = node->get(ch);
      } else {
        return nullptr;
      }
    }

    return node;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
