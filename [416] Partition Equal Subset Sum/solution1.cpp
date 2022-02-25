/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    3182
 * Dislikes: 74
 * Total Accepted:    210.5K
 * Total Submissions: 477.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.empty()) {
      return false;
    }

    auto sum = accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 == 1) {
      return false;
    }

    auto target = sum / 2;

    // dp[i][j] 表示从 nums[0] 到 nums[i] 中选择任意个数，是否存在和为 j 的
    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

    for (auto i = 1; i < nums.size(); ++i) {
      for (auto j = 0; j <= target; ++j) {
        if (nums[i] == j) {
          dp[i][j] = true;
        } else if (nums[i] < j) {
          // 当前数 nums[i] 比和小，选不选都可以
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        } else if (nums[i] > j) {
          // 当前数 nums[i] 比和大，不能选
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
