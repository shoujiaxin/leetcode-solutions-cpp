/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (45.01%)
 * Likes:    3303
 * Dislikes: 375
 * Total Accepted:    543.8K
 * Total Submissions: 1.2M
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
    if (!digits.empty()) {
      string path;
      backtrack(digits, path, 0);
    }

    return res;
  }

 private:
  std::map<int, string> keyboard{
      {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
      {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
  };
  vector<string> res;

  void backtrack(const string& digits, string& path, int i) {
    if (path.size() == digits.size()) {
      res.push_back(path);
      return;
    }

    for (const auto& c : keyboard[digits[i] - '0']) {
      path.push_back(c);
      backtrack(digits, path, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
