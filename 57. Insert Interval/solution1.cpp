/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (33.33%)
 * Likes:    2255
 * Dislikes: 219
 * Total Accepted:    300.2K
 * Total Submissions: 871.3K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 * Example 3:
 *
 *
 * Input: intervals = [], newInterval = [5,7]
 * Output: [[5,7]]
 *
 *
 * Example 4:
 *
 *
 * Input: intervals = [[1,5]], newInterval = [2,3]
 * Output: [[1,5]]
 *
 *
 * Example 5:
 *
 *
 * Input: intervals = [[1,5]], newInterval = [2,7]
 * Output: [[1,7]]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
 * intervals is sorted by intervals[i][0] in ascending order.
 * newInterval.length == 2
 * 0 <= newInterval[0] <= newInterval[1] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    intervals.push_back(newInterval);

    return merge(intervals);
  }

 private:
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
