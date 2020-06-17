/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 *
 * https://leetcode.com/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (51.85%)
 * Likes:    424
 * Dislikes: 23
 * Total Accepted:    16.1K
 * Total Submissions: 30.9K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * Given an array A of positive integers, A[i] represents the value of the i-th
 * sightseeing spot, and two sightseeing spots i and j have distance j - i
 * between them.
 *
 * The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) :
 * the sum of the values of the sightseeing spots, minus the distance between
 * them.
 *
 * Return the maximum score of a pair of sightseeing spots.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [8,1,5,2,6]
 * Output: 11
 * Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= A.length <= 50000
 * 1 <= A[i] <= 1000
 *
 */

// @lc code=start
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    if (A.empty()) {
      return 0;
    }

    auto res = 0;
    auto mx = A[0] + 0;

    for (auto j = 1; j < A.size(); ++j) {
      res = max(res, mx + A[j] - j);
      mx = max(mx, A[j] + j);
    }

    return res;
  }
};
// @lc code=end
