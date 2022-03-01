/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (30.19%)
 * Likes:    694
 * Dislikes: 612
 * Total Accepted:    67.8K
 * Total Submissions: 222.1K
 * Testcase Example:  '"112358"'
 *
 * An additive number is a string whose digits can form an additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 *
 * Given a string containing only digits, return true if it is an additive
 * number or false otherwise.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 *
 * Example 1:
 *
 *
 * Input: "112358"
 * Output: true
 * Explanation:
 * The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 *
 * Example 2:
 *
 *
 * Input: "199100199"
 * Output: true
 * Explanation:
 * The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num.length <= 35
 * num consists only of digits.
 *
 *
 *
 * Follow up: How would you handle overflow for very large input integers?
 *
 */

// @lc code=start
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    const auto n = num.size();
    if (n < 3) {
      return false;
    }

    for (auto len1 = 1; len1 <= n / 2; ++len1) {
      if (num[0] == '0' && len1 > 1) {
        break;
      }
      for (auto len2 = 1; len2 < n - len1 && len2 <= n / 2; ++len2) {
        if (num[len1] == '0' && len2 > 1) {
          break;
        }
        const auto x = stoll(num.substr(0, len1));
        const auto y = stoll(num.substr(len1, len2));
        if (backtracking(num, len1 + len2, x, y)) {
          return true;
        }
      }
    }

    return false;
  }

 private:
  bool backtracking(const string& num, int index, long long x, long long y) {
    if (index == num.size()) {
      return true;
    }

    const auto n = num.size();
    auto result = false;
    for (auto len = 1; len <= n - index && len <= n / 2; ++len) {
      if (num[index] == '0' && len > 1) {
        break;
      }
      const auto z = stoll(num.substr(index, len));
      if (x + y == z) {
        result |= backtracking(num, index + len, y, z);
      }
    }

    return result;
  }
};
// @lc code=end
