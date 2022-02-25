/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (53.09%)
 * Likes:    412
 * Dislikes: 235
 * Total Accepted:    105K
 * Total Submissions: 197.8K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "USA"
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "FlaG"
 * Output: False
 *
 *
 *
 *
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 *
 */

// @lc code=start
class Solution {
 public:
  bool detectCapitalUse(string word) {
    auto isFirstUpper = isupper(word[0]);

    if (!isFirstUpper) {
      for (auto it = word.cbegin() + 1; it < word.cend(); ++it) {
        if (isupper(*it)) {
          return false;
        }
      }
    } else if (word.size() > 1) {
      auto isSecondUpper = isupper(word[1]);

      for (auto it = word.cbegin() + 2; it < word.cend(); ++it) {
        if (isSecondUpper && islower(*it) || !isSecondUpper && isupper(*it)) {
          return false;
        }
      }
    }

    return true;
  }
};
// @lc code=end
