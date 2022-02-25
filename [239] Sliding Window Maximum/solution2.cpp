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

    vector<int> res(nums.size() - k + 1, 0);

    deque<int> dque;  // 单调（减）队列
    for (auto i = 1 - k, j = 0; j < nums.size(); ++i, ++j) {
      // 窗口左边界在 dque 中，将其移除
      if (i > 0 && dque.front() == nums[i - 1]) {
        dque.pop_front();
      }

      // 移除 dque 中所有小于右边界的元素，确保单调性
      while (!dque.empty() && dque.back() < nums[j]) {
        dque.pop_back();
      }

      dque.push_back(nums[j]);

      if (i >= 0) {
        res[i] = dque.front();
      }
    }

    return res;
  }
};
// @lc code=end
