/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (54.90%)
 * Likes:    1054
 * Dislikes: 202
 * Total Accepted:    88.8K
 * Total Submissions: 161.3K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "HH:MM" format, return the
 * minimum minutes difference between any two time-points in the list.
 *
 * Example 1:
 * Input: timePoints = ["23:59","00:00"]
 * Output: 1
 * Example 2:
 * Input: timePoints = ["00:00","23:59","00:00"]
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * 2 <= timePoints.length <= 2 * 10^4
 * timePoints[i] is in the format "HH:MM".
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    const auto time = getTime(timePoints.front());
    timePoints.emplace_back(to_string(time.first + 24) + ":" +
                            to_string(time.second));

    auto res = 24 * 3600;
    for (auto i = 1; i < timePoints.size(); ++i) {
      res = min(res, diff(timePoints[i - 1], timePoints[i]));
    }
    return res;
  }

 private:
  pair<int, int> getTime(const string& time) {
    const auto hour = stoi(time.substr(0, 2));
    const auto minute = stoi(time.substr(3, 2));
    return {hour, minute};
  }

  int diff(const string& timeStr1, const string timeStr2) {
    const auto time1 = getTime(timeStr1);
    const auto time2 = getTime(timeStr2);
    return 60 * (time2.first - time1.first) + time2.second - time1.second;
  }
};
// @lc code=end
