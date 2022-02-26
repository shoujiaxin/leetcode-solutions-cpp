/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Medium (52.94%)
 * Likes:    1352
 * Dislikes: 1507
 * Total Accepted:    117.1K
 * Total Submissions: 218.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 *
 * In one move, you can increment n - 1 elements of the array by 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 * Explanation: Only three moves are needed (remember each move increments two
 * elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    const auto minVal = *min_element(nums.cbegin(), nums.cend());
    auto result = 0;
    for (const auto& n : nums) {
      result += n - minVal;
    }
    return result;
  }
};
// @lc code=end
