/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (43.30%)
 * Likes:    576
 * Dislikes: 1017
 * Total Accepted:    202.6K
 * Total Submissions: 467.7K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 * Example 1:
 *
 *
 * Input: "hello"
 * Output: "holle"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "leetcode"
 * Output: "leotcede"
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    auto left = s.begin();
    auto right = s.end() - 1;

    while (left < right) {
      while (left < right && !isVowel(*left)) {
        ++left;
      }
      while (left < right && !isVowel(*right)) {
        --right;
      }

      swap(*left, *right);
      ++left;
      --right;
    }

    return s;
  }

 private:
  bool isVowel(const char& c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};
// @lc code=end
