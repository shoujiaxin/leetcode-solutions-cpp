/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (62.53%)
 * Likes:    966
 * Dislikes: 66
 * Total Accepted:    106.9K
 * Total Submissions: 170.8K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 *
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: text = "nlaebolko"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: text = "loonbalxballpoon"
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: text = "leetcode"
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> charCounter;
    for (const auto& ch : text) {
      ++charCounter[ch];
    }

    auto cnt = 0;
    while (charCounter['b'] >= 1 && charCounter['a'] >= 1 &&
           charCounter['l'] >= 2 && charCounter['o'] >= 2 &&
           charCounter['n'] >= 1) {
      ++cnt;
      charCounter['b'] -= 1;
      charCounter['a'] -= 1;
      charCounter['l'] -= 2;
      charCounter['o'] -= 2;
      charCounter['n'] -= 1;
    }

    return cnt;
  }
};
// @lc code=end
