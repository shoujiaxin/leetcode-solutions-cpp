/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.71%)
 * Likes:    1705
 * Dislikes: 121
 * Total Accepted:    432.4K
 * Total Submissions: 945.8K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }

    // 初始值设为前三个数的和
    auto sum = accumulate(nums.cbegin(), nums.cbegin() + 3, 0);

    quick_sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      auto l = i + 1;
      auto r = nums.size() - 1;

      while (l < r) {
        auto temp = nums[i] + nums[l] + nums[r];
        if (abs(temp - target) < abs(sum - target)) {
          sum = temp;
        }

        if (temp < target) {
          ++l;
        } else if (temp > target) {
          --r;
        } else {
          return sum;
        }
      }
    }

    return sum;
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
