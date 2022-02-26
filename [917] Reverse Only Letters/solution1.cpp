/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (60.63%)
 * Likes:    1371
 * Dislikes: 50
 * Total Accepted:    128.4K
 * Total Submissions: 210.9K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string s, reverse the string according to the following rules:
 *
 *
 * All the characters that are not English letters remain in the same
 * position.
 * All the English letters (lowercase or uppercase) should be reversed.
 *
 *
 * Return s after reversing it.
 *
 *
 * Example 1:
 * Input: s = "ab-cd"
 * Output: "dc-ba"
 * Example 2:
 * Input: s = "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * Example 3:
 * Input: s = "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists of characters with ASCII values in the range [33, 122].
 * s does not contain '\"' or '\\'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    auto left = s.begin();
    auto right = s.end() - 1;
    while (left < right) {
      if (!isalpha(*left)) {
        ++left;
      } else if (!isalpha(*right)) {
        --right;
      } else {
        swap(*left, *right);
        ++left;
        --right;
      }
    }
    return s;
  }
};
// @lc code=end
