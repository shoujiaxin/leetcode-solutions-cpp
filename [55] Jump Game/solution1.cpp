/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (34.49%)
 * Likes:    4237
 * Dislikes: 326
 * Total Accepted:    477.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i][j] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    auto maxDist = 0;

    auto n = nums.size();
    for (auto i = 0; i < n; ++i) {
      // i <= maxDist 为可到达，否则无法到达
      if (i <= maxDist) {
        maxDist = max(maxDist, i + nums[i]);

        if (maxDist >= n - 1) {
          return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
