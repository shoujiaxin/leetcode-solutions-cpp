/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    1081
 * Dislikes: 126
 * Total Accepted:    157.3K
 * Total Submissions: 399.5K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * Example 1:
 *
 *
 * Input: [5,7]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1]
 * Output: 0
 */

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    auto offset = 0;

    while (m != n) {
      m >>= 1;
      n >>= 1;
      ++offset;
    }

    return m << offset;
  }
};
// @lc code=end
