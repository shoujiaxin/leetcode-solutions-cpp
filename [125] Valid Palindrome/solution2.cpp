/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.70%)
 * Likes:    3615
 * Dislikes: 5167
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    auto left = s.cbegin();
    auto right = s.cend() - 1;

    while (left < right) {
      while (left < right && !isalnum(*left)) {
        ++left;
      }
      while (left < right && !isalnum(*right)) {
        --right;
      }
      if (left < right) {
        if (tolower(*left) != tolower(*right)) {
          return false;
        }
        ++left;
        --right;
      }
    }

    return true;
  }
};
// @lc code=end
