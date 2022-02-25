/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 *
 * https://leetcode.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (45.21%)
 * Likes:    535
 * Dislikes: 70
 * Total Accepted:    25.9K
 * Total Submissions: 57.2K
 * Testcase Example:  '10'
 *
 *
 * Given a non-negative integer N, find the largest number that is less than or
 * equal to N with monotone increasing digits.
 *
 * (Recall that an integer has monotone increasing digits if and only if each
 * pair of adjacent digits x and y satisfy x .)
 *
 *
 * Example 1:
 *
 * Input: N = 10
 * Output: 9
 *
 *
 *
 * Example 2:
 *
 * Input: N = 1234
 * Output: 1234
 *
 *
 *
 * Example 3:
 *
 * Input: N = 332
 * Output: 299
 *
 *
 *
 * Note:
 * N is an integer in the range [0, 10^9].
 *
 */

// @lc code=start
class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    auto numStr = to_string(N);

    for (auto i = numStr.rbegin() + 1; i < numStr.rend(); ++i) {
      if (*i > *(i - 1)) {
        *i -= 1;
        for (auto j = i - 1; j >= numStr.rbegin(); --j) {
          *j = '9';
        }
      }
    }

    return stoi(numStr);
  }
};
// @lc code=end
