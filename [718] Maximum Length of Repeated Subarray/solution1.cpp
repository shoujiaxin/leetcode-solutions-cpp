/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (48.87%)
 * Likes:    1207
 * Dislikes: 46
 * Total Accepted:    60.8K
 * Total Submissions: 123.9K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 *
 * Example 1:
 *
 *
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation:
 * The repeated subarray with maximum length is [3, 2, 1].
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    auto lenA = A.size();
    auto lenB = B.size();

    // dp[i][j] 表示 A[i:] 和 B[j:] 的最长重复子数组长度
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
    auto res = 0;

    for (auto i = 1; i <= lenA; ++i) {
      for (auto j = 1; j <= lenB; ++j) {
        dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
        res = max(res, dp[i][j]);
      }
    }

    return res;
  }
};
// @lc code=end
