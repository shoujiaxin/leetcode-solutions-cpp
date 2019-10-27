/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (47.21%)
 * Likes:    4143
 * Dislikes: 483
 * Total Accepted:    473.4K
 * Total Submissions: 1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int maxValue = min(height[0], height[1]);

    for (decltype(height.size()) i = 0; i < height.size() - 1; ++i) {
      for (auto j = i + 1; j < height.size(); ++j) {
        int value = min(height[i], height[j]) * (j - i);
        if (value > maxValue) {
          maxValue = value;
        }
      }
    }

    return maxValue;
  }
};
// @lc code=end
