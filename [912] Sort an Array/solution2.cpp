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
    heapSort(nums.begin(), nums.end());
    return nums;
  }

 private:
  template <typename RandomIt, typename Distance>
  void maxHeapify(RandomIt first, Distance start, Distance end) {
    auto parent = start;
    auto child = 2 * parent + 1;

    while (child < end) {
      if (child + 1 < end && *(first + child) < *(first + child + 1)) {
        ++child;
      }

      if (*(first + parent) > *(first + child)) {
        return;
      }

      std::swap(*(first + parent), *(first + child));
      parent = child;
      child = 2 * parent + 1;
    }
  }

  template <typename RandomIt>
  void heapSort(RandomIt first, RandomIt last) {
    // 构造最大堆
    auto len = last - first;
    for (auto i = len / 2 - 1; i >= 0; --i) {
      maxHeapify(first, i, len);
    }

    // 依次取出最大值：交换根节点和最后一个节点，再取出最后一个节点
    for (auto i = len - 1; i > 0; --i) {
      std::swap(*first, *(first + i));
      maxHeapify(first, static_cast<decltype(i)>(0), i);
    }
  }
};
// @lc code=end
