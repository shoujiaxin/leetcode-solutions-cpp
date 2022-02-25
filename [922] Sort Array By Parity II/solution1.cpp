/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (68.76%)
 * Likes:    818
 * Dislikes: 54
 * Total Accepted:    105.8K
 * Total Submissions: 151.3K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 *
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    auto j = 1;
    for (auto i = 0; i < A.size() - 1; i += 2) {
      if (A[i] % 2 != 0) {
        while (A[j] % 2 != 0) {
          j += 2;
        }

        swap(A[i], A[j]);
      }
    }
    return A;
  }
};
// @lc code=end
