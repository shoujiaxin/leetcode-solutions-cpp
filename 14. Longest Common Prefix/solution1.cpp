/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.25%)
 * Likes:    1674
 * Dislikes: 1514
 * Total Accepted:    565K
 * Total Submissions: 1.6M
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

    string commonPrefix;
    auto minSize = strs[0].size();

    for (const auto& str : strs) {
      if (str.size() < minSize) {
        minSize = str.size();
      }
    }

    for (decltype(minSize) i = 0; i != minSize; ++i) {
      for (const auto& str : strs) {
        if (strs[0][i] != str[i]) {
          return commonPrefix;
        }
      }

      commonPrefix += strs[0][i];
    }

    return commonPrefix;
  }
};
// @lc code=end
