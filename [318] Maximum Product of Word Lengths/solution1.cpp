/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (56.64%)
 * Likes:    1715
 * Dislikes: 94
 * Total Accepted:    143.1K
 * Total Submissions: 252.5K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    const auto n = words.size();
    // 第 i 个 int 元素 masks[i] 的二进制从第 0 位到第 25 位
    // 表示 words[i] 是否含有 a-z 的字母（1 有，0 无）
    vector<int> masks(n, 0);
    for (auto i = 0; i < n; ++i) {
      for (const auto& ch : words[i]) {
        masks[i] |= 1 << (ch - 'a');
      }
    }

    decltype(words[0].size()) res = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = i + 1; j < n; ++j) {
        if ((masks[i] & masks[j]) == 0) {
          res = max(res, words[i].size() * words[j].size());
        }
      }
    }
    return res;
  }
};
// @lc code=end
