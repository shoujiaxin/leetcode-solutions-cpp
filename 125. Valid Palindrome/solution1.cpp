/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.71%)
 * Likes:    729
 * Dislikes: 2137
 * Total Accepted:    427.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    auto iter = s.begin();
    while (iter != s.end()) {
      if (isalpha(*iter)) {
        *iter = tolower(*iter);  // Convert to lowercase
      } else if (!isdigit(*iter)) {
        s.erase(iter);  // Remove non-alphabetic character
        continue;
      }
      ++iter;
    }

    for (decltype(s.size()) i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
