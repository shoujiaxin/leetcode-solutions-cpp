/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.07%)
 * Likes:    3379
 * Dislikes: 255
 * Total Accepted:    515.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& inter1, const vector<int>& inter2) {
           return inter1[0] < inter2[0];
         });

    int i = 0;
    for (int j = 1; j < intervals.size(); ++j) {
      if (intervals[i][1] >= intervals[j][0]) {
        intervals[i][1] = max(intervals[i][1], intervals[j][1]);  // 区间有重叠
      } else {
        intervals[++i] = intervals[j];  // 区间没有重叠
      }
    }
    intervals.resize(i + 1);

    return intervals;
  }
};
// @lc code=end
