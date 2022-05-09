/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.78%)
 * Likes:    5834
 * Dislikes: 715
 * Total Accepted:    804.7K
 * Total Submissions: 3.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    const int n = nums.size();
    if (n < 3) {
      return res;
    }

    quick_sort(nums.begin(), nums.end());
    if (nums.front() > 0) {
      return res;  // 最小的元素大于 0，不存在三数和为 0
    }

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) {
        return res;  // 之后的数都大于 0，直接返回
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;  // 避免重复解
      }

      auto l = i + 1;
      auto r = n - 1;
      while (l < r) {
        const auto sum = nums[i] + nums[l] + nums[r];
        if (sum < 0) {
          ++l;
        } else if (sum > 0) {
          --r;
        } else {
          res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});

          // 避免重复解
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }
          while (l < r && nums[r] == nums[r - 1]) {
            --r;
          }
          ++l;
          --r;
        }
      }
    }

    return res;
  }

 private:
  template <typename It>
  void quick_sort(It first, It last) {
    if (first == last) {
      return;
    }

    auto pivot = *first;
    auto i = first;
    auto j = last - 1;
    while (i < j) {
      while (i < j && *j >= pivot) {
        --j;
      }
      *i = *j;
      while (i < j && *i <= pivot) {
        ++i;
      }
      *j = *i;
    }
    *i = pivot;

    quick_sort(first, i);
    quick_sort(i + 1, last);
  }
};
// @lc code=end
