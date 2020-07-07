/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (33.39%)
 * Likes:    1909
 * Dislikes: 322
 * Total Accepted:    329.6K
 * Total Submissions: 986.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) {
      return {};
    }

    sort(nums.begin(), nums.end());

    set<vector<int>> res;

    for (auto a = 0; a < nums.size() - 3; ++a) {
      for (auto b = a + 1; b < nums.size() - 2; ++b) {
        auto c = b + 1;
        auto d = nums.size() - 1;

        while (c < d) {
          auto sum = nums[a] + nums[b] + nums[c] + nums[d];

          if (sum < target) {
            ++c;
          } else if (sum > target) {
            --d;
          } else {
            res.insert({nums[a], nums[b], nums[c], nums[d]});
            ++c;
          }
        }
      }
    }

    return vector<vector<int>>(res.cbegin(), res.cend());
  }
};
// @lc code=end
