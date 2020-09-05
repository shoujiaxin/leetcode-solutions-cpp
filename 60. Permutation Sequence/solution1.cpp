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
    string nums(n, '0');
    for (auto i = 0; i < n; ++i) {
      nums[i] = i + 1 + '0';
    }

    for (auto i = 0; i < k - 1; ++i) {
      next_permutation(nums.begin(), nums.end());
    }

    return nums;
  }
};
// @lc code=end
