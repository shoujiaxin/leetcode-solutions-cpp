/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.40%)
 * Likes:    2698
 * Dislikes: 341
 * Total Accepted:    463.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return results;
    }

    if (results.empty()) {
      for (const auto& c : keyboard[digits.back() - '0']) {
        results.push_back(std::string(1, c));
      }
    } else {
      decltype(results) temp;

      for (const auto& c : keyboard[digits.back() - '0']) {
        for (const auto& s : results) {
          temp.push_back(std::string(1, c) + s);
        }
      }

      results = std::move(temp);
    }

    digits.pop_back();
    return letterCombinations(digits);
  }

 private:
  static std::map<int, string> keyboard;
  vector<string> results;
};

std::map<int, string> Solution::keyboard{
    {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
    {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
};
// @lc code=end
