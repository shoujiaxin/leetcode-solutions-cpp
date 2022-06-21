/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (75.59%)
 * Likes:    1866
 * Dislikes: 119
 * Total Accepted:    99.7K
 * Total Submissions: 131.9K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * Given a list of strings words and a string pattern, return a list of
 * words[i] that match pattern. You may return the answer in any order.
 *
 * A word matches the pattern if there exists a permutation of letters p so
 * that after replacing every letter x in the pattern with p(x), we get the
 * desired word.
 *
 * Recall that a permutation of letters is a bijection from letters to letters:
 * every letter maps to another letter, and no two letters map to the same
 * letter.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a ->
 * m, b -> e, ...}.
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
 * permutation, since a and b map to the same letter.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","b","c"], pattern = "a"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 20
 * 1 <= words.length <= 50
 * words[i].length == pattern.length
 * pattern and words[i] are lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    for (const auto& word : words) {
      if (match(word, pattern)) {
        res.emplace_back(word);
      }
    }
    return res;
  }

 private:
  bool match(const string_view& word, const string_view& pattern) {
    if (word.size() != pattern.size()) {
      return false;
    }

    unordered_map<char, char> w2p;
    unordered_map<char, char> p2w;
    for (auto i = 0; i < word.size(); ++i) {
      const auto& w = word[i];
      const auto& p = pattern[i];
      if (w2p.count(w) == 0 && p2w.count(p) == 0) {
        w2p[w] = p;
        p2w[p] = w;
      } else if (w2p.count(w) != 0 && p2w.count(p) != 0) {
        if (w2p[w] != p || p2w[p] != w) {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
