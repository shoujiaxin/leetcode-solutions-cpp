/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 *
 * https://leetcode.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (37.47%)
 * Likes:    239
 * Dislikes: 362
 * Total Accepted:    32.2K
 * Total Submissions: 85.9K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * Given an array points where points[i] = [xi, yi] represents a point on the
 * X-Y plane, return true if these points are a boomerang.
 *
 * A boomerang is a set of three points that are all distinct and not in a
 * straight line.
 *
 *
 * Example 1:
 * Input: points = [[1,1],[2,3],[3,2]]
 * Output: true
 * Example 2:
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * points.length == 3
 * points[i].length == 2
 * 0 <= xi, yi <= 100
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    const auto x1 = points[0][0] - points[1][0];
    const auto y1 = points[0][1] - points[1][1];

    const auto x2 = points[0][0] - points[2][0];
    const auto y2 = points[0][1] - points[2][1];

    return x1 * y2 != x2 * y1;
  }
};
// @lc code=end
