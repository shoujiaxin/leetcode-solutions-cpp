/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 *
 * https://leetcode.com/problems/h-index/description/
 *
 * algorithms
 * Medium (35.79%)
 * Likes:    774
 * Dislikes: 1320
 * Total Accepted:    186.5K
 * Total Submissions: 514.2K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of citations (each citation is a non-negative integer) of a
 * researcher, write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N −
 * h papers have no more than h citations each."
 *
 * Example:
 *
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had
 * ⁠            received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining
 * two with no more than 3 citations each, her h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one is taken
 * as the h-index.
 *
 */

// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), std::greater<int>());

    auto res = 0;
    for (auto i = 0; i < citations.size(); ++i) {
      if (citations[i] > i) {
        ++res;
      }
    }

    return res;
  }
};
// @lc code=end
