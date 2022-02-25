/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.97%)
 * Likes:    2447
 * Dislikes: 1822
 * Total Accepted:    734.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */

// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }

    return longestCommonPrefix(strs, 0, strs.size() - 1);
  }

 private:
  string longestCommonPrefix(const vector<string>& strs, int start, int end) {
    if (start == end) {
      return strs[start];
    }

    auto mid = start + (end - start) / 2;
    auto leftLcp = longestCommonPrefix(strs, start, mid);
    auto rightLcp = longestCommonPrefix(strs, mid + 1, end);

    return commonPrefix(leftLcp, rightLcp);
  }

  string commonPrefix(const string& str1, const string& str2) {
    auto minLength = min(str1.size(), str2.size());

    for (auto i = 0; i < minLength; ++i) {
      if (str1[i] != str2[i]) {
        return str1.substr(0, i);
      }
    }

    return str1.substr(0, minLength);
  }
};
// @lc code=end
