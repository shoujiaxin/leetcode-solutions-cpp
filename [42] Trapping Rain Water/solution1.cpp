/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (56.54%)
 * Likes:    18235
 * Dislikes: 257
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    const int n = height.size();

    vector<int> leftMax(n, 0);
    leftMax[0] = height[0];
    for (auto i = 1; i < n; ++i) {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    vector<int> rightMax(n, 0);
    rightMax[n - 1] = height[n - 1];
    for (auto i = n - 2; i >= 0; --i) {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    auto res = 0;
    for (auto i = 0; i < n; ++i) {
      res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
  }
};
// @lc code=end
