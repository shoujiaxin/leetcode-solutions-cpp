/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.70%)
 * Likes:    9338
 * Dislikes: 414
 * Total Accepted:    666.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.cbegin(), nums.cend());

    auto res = 0;

    for (auto n : nums) {
      if (numSet.count(n - 1) > 0) {
        // 当前数字已包含在更大的范围中，跳过
        continue;
      }

      auto cur = n;
      auto len = 1;
      while (numSet.count(cur + 1)) {
        ++cur;
        ++len;
      }

      res = max(res, len);
    }

    return res;
  }
};
// @lc code=end
