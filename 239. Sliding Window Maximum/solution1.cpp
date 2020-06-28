/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (41.93%)
 * Likes:    3334
 * Dislikes: 168
 * Total Accepted:    265K
 * Total Submissions: 623.3K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 *
 * Follow up:
 * Could you solve it in linear time?
 *
 * Example:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty() || k == 0) {
      return {};
    }

    vector<int> res;

    auto left = 0;
    auto right = left + k - 1;

    auto maxVal = nums[left];
    auto maxIdx = left;

    // 找到第一个窗口中的最大值
    for (auto i = left + 1; i <= right; ++i) {
      if (nums[i] > maxVal) {
        maxVal = nums[i];
        maxIdx = i;
      }
    }
    res.push_back(maxVal);

    while (right < nums.size() - 1) {
      if (nums[right + 1] >= maxVal) {
        maxVal = nums[right + 1];
        maxIdx = right + 1;
      } else if (left == maxIdx) {
        maxVal = nums[left + 1];
        maxIdx = left + 1;
        for (auto i = left + 2; i <= right + 1; ++i) {
          if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIdx = i;
          }
        }
      }

      res.push_back(maxVal);

      ++left;
      ++right;
    }

    return res;
  }
};
// @lc code=end
