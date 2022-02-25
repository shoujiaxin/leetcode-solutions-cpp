/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.00%)
 * Likes:    6665
 * Dislikes: 391
 * Total Accepted:    1.1M
 * Total Submissions: 4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    string subStr;
    auto maxLength = subStr.size();
    auto lastBegin = s.cbegin();

    for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
      if (subStr.find(*iter) == string::npos) {
        subStr.push_back(*iter);
      } else {
        if (subStr.size() > maxLength) {
          maxLength = subStr.size();
        }

        subStr.clear();
        iter = lastBegin + 1;
        lastBegin = iter;
        subStr.push_back(*iter);
      }
    }

    return subStr.size() > maxLength ? subStr.size() : maxLength;
  }
};
// @lc code=end
