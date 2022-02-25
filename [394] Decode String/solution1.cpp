/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (49.51%)
 * Likes:    3384
 * Dislikes: 170
 * Total Accepted:    220.4K
 * Total Submissions: 440.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 *
 */

// @lc code=start
string operator*(const string &str, int n) {
  string res;
  for (auto i = 0; i < n; ++i) {
    res += str;
  }
  return res;
}

class Solution {
 public:
  string decodeString(string s) {
    stack<int> numStk;
    stack<string> strStk;

    string res;

    for (auto i = 0; i < s.size();) {
      // 数字
      if (isdigit(s[i])) {
        auto j = i + 1;
        while (isdigit(s[j])) {
          ++j;
        }
        numStk.push(stoi(s.substr(i, j - i)));
        i = j;
      }
      // 左括号
      else if (s[i] == '[') {
        ++i;
        auto j = i;
        while (isalpha(s[j])) {
          ++j;
        }
        strStk.push(s.substr(i, j - i));
        i = j;
      }
      // 右括号
      else if (s[i] == ']') {
        auto str = strStk.top() * numStk.top();
        numStk.pop();
        strStk.pop();

        if (numStk.empty()) {
          res += str;
        } else {
          strStk.top() += str;
        }

        ++i;
      }
      // 右括号后的字符
      else {
        if (numStk.empty()) {
          res += s[i];
          ++i;
        } else {
          auto j = i + 1;
          while (isalpha(s[j])) {
            ++j;
          }
          strStk.top() += s.substr(i, j - i);
          i = j;
        }
      }
    }

    return res;
  }
};
// @lc code=end
