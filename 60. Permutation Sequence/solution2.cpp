/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (38.17%)
 * Likes:    1795
 * Dislikes: 341
 * Total Accepted:    207.8K
 * Total Submissions: 538.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the k^th permutation sequence.
 *
 * Note:
 *
 *
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 3
 * Output: "213"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, k = 9
 * Output: "2314"
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string getPermutation(int n, int k) {
    // 保存 1 ~ n 的阶乘
    vector<int> factorial(n);
    factorial[0] = 1;
    for (auto i = 1; i < n; ++i) {
      factorial[i] = factorial[i - 1] * i;
    }

    --k;
    string res;
    vector<int> valid(n + 1, 1);  // 数字 1 ~ n 是否可用

    for (auto i = 1; i <= n; ++i) {
      // 以第 i 个数字开头的排列共 (n - i)! 个
      auto order = k / factorial[n - i] + 1;

      // 确定结果中第 i 位数字
      for (auto j = 1; j <= n; ++j) {
        order -= valid[j];
        if (!order) {
          res += j + '0';
          valid[j] = 0;
          break;
        }
      }

      // 缩小范围
      k %= factorial[n - i];
    }

    return res;
  }
};
// @lc code=end
