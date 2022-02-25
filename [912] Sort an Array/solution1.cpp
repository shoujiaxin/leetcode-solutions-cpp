/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.68%)
 * Likes:    301
 * Dislikes: 211
 * Total Accepted:    57.2K
 * Total Submissions: 91.2K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 *
 *
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums.begin(), nums.end());
    return nums;
  }

 private:
  template <typename It>
  void quickSort(It first, It last) {
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

    quickSort(first, i);
    quickSort(i + 1, last);
  }
};
// @lc code=end
