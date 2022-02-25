/*
 * @lc app=leetcode id=1447 lang=cpp
 *
 * [1447] Simplified Fractions
 *
 * https://leetcode.com/problems/simplified-fractions/description/
 *
 * algorithms
 * Medium (63.16%)
 * Likes:    220
 * Dislikes: 31
 * Total Accepted:    19.6K
 * Total Submissions: 30.8K
 * Testcase Example:  '2'
 *
 * Given an integer n, return a list of all simplified fractions between 0 and
 * 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can
 * return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: ["1/2"]
 * Explanation: "1/2" is the only unique fraction with a denominator
 * less-than-or-equal-to 2.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: ["1/2","1/3","2/3"]
 *
 *
 * Example 3:
 *
 *
 * Input: n = 4
 * Output: ["1/2","1/3","1/4","2/3","3/4"]
 * Explanation: "2/4" is not a simplified fraction because it can be simplified
 * to "1/2".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> result;
    for (auto i = 1; i < n; ++i) {
      for (auto j = i + 1; j <= n; ++j) {
        if (gcd(i, j) == 1) {
          result.emplace_back(to_string(i) + "/" + to_string(j));
        }
      }
    }
    return result;
  }

 private:
  int gcd(int a, int b) {
    while (b) {
      auto temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }
};
// @lc code=end
