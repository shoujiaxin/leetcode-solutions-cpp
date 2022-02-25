/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (29.60%)
 * Likes:    1242
 * Dislikes: 128
 * Total Accepted:    100.9K
 * Total Submissions: 337.8K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 *
 * Example 1:
 *
 *
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 *
 *
 * Example 2:
 *
 *
 * Input: "abcd"
 * Output: "dcbabcd"
 */

// @lc code=start
class Solution {
 public:
  string shortestPalindrome(string s) {
    auto base = 131;
    auto mod = 1000000007;

    auto best = -1;  // s 最长回文前缀的长度

    auto left = 0;   // 前缀的正序哈希值
    auto right = 0;  // 前缀的逆序哈希值
    auto mul = 1;    // 用于计算逆序哈希值

    for (auto i = 0; i < s.size(); ++i) {
      // 递推地计算哈希值
      left = (static_cast<long long>(left) * base + s[i]) % mod;
      right = (right + static_cast<long long>(mul) * s[i]) % mod;

      // 正序、逆序哈希值相同，为回文串
      if (left == right) {
        best = i;
      }

      mul = static_cast<long long>(mul) * base % mod;
    }

    string add = (best == s.size() - 1) ? "" : s.substr(best + 1);
    reverse(add.begin(), add.end());

    return add + s;
  }
};
// @lc code=end
