/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 *
 * https://leetcode.com/problems/string-matching-in-an-array/description/
 *
 * algorithms
 * Easy (63.88%)
 * Likes:    568
 * Dislikes: 77
 * Total Accepted:    58.3K
 * Total Submissions: 91.3K
 * Testcase Example:  '["mass","as","hero","superhero"]'
 *
 * Given an array of string words. Return all strings in words which is
 * substring of another word in any order. 
 *
 * String words[i] is substring of words[j], if can be obtained removing some
 * characters to left and/or right side of words[j].
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["mass","as","hero","superhero"]
 * Output: ["as","hero"]
 * Explanation: "as" is substring of "mass" and "hero" is substring of
 * "superhero".
 * ["hero","as"] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["leetcode","et","code"]
 * Output: ["et","code"]
 * Explanation: "et", "code" are substring of "leetcode".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["blue","green","bu"]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 30
 * words[i] contains only lowercase English letters.
 * It's guaranteed that words[i] will be unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    std::vector<std::string> result;
    for (auto i = 0; i < words.size(); ++i) {
      for (auto j = 0; j < words.size(); ++j) {
        if (i != j && words[j].find(words[i]) != std::string::npos) {
          result.emplace_back(words[i]);
          break;
        }
      }
    }
    return result;
  }
};
// @lc code=end
