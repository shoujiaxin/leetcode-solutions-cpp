/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (52.66%)
 * Likes:    3125
 * Dislikes: 219
 * Total Accepted:    549.1K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quick_select(nums.begin(), nums.end(), nums.size() - k + 1);
  }

 private:
  template <typename RandomIt>
  auto quick_select(RandomIt first, RandomIt last, int k) -> decltype(*first) {
    if (first == last) {
      return *first;
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

    auto index = std::distance(first, i) + 1;
    if (index == k) {
      return *i;
    }

    return (index < k) ? quick_select(i + 1, last, k - index)
                       : quick_select(first, i, k);
  }
};
// @lc code=end
