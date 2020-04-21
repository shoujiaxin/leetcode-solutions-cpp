/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (68.25%)
 * Likes:    871
 * Dislikes: 84
 * Total Accepted:    185.8K
 * Total Submissions: 271.8K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    string res;

    istringstream istm(s);
    string word;
    while (istm >> word) {
      reverse(word.begin(), word.end());
      res += word + " ";
    }

    if (!res.empty() && res.back() == ' ') {
      res.pop_back();
    }

    return res;
  }
};
// @lc code=end
