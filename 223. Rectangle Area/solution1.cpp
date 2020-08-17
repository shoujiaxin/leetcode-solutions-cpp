/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (37.63%)
 * Likes:    429
 * Dislikes: 753
 * Total Accepted:    108.6K
 * Total Submissions: 287.3K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 *
 *
 *
 * Example:
 *
 *
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 *
 * Note:
 *
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 *
 */

// @lc code=start
class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    auto area1 = (C - A) * (D - B);
    auto area2 = (G - E) * (H - F);

    if (C <= E || B >= H || A >= G || D <= F) {
      return area1 + area2;  // 没有重叠
    }

    // 重叠部分左下角
    auto x1 = max(A, E);
    auto y1 = max(B, F);
    // 重叠部分右上角
    auto x2 = min(C, G);
    auto y2 = min(D, H);

    return area1 - (x2 - x1) * (y2 - y1) + area2;
  }
};
// @lc code=end
