/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.83%)
 * Likes:    1691
 * Dislikes: 540
 * Total Accepted:    324.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);

    for (auto i = 2; i * i < n; ++i) {
      if (isPrime[i]) {
        // 如果 i 为素数，则 i 的整数倍都不是素数
        for (auto j = i * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    auto cnt = 0;
    for (auto i = 2; i < n; ++i) {
      if (isPrime[i]) {
        ++cnt;
      }
    }

    return cnt;
  }
};
// @lc code=end
