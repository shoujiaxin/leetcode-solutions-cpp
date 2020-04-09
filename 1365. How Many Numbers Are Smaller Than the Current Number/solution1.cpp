/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 *
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
 *
 * algorithms
 * Easy (85.68%)
 * Likes:    308
 * Dislikes: 11
 * Total Accepted:    39K
 * Total Submissions: 46.1K
 * Testcase Example:  '[8,1,2,2,3]'
 *
 * Given the array nums, for each nums[i] find out how many numbers in the
 * array are smaller than it. That is, for each nums[i] you have to count the
 * number of valid j's such that j != i and nums[j] < nums[i].
 *
 * Return the answer in an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [8,1,2,2,3]
 * Output: [4,0,1,1,3]
 * Explanation:
 * For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
 * For nums[1]=1 does not exist any smaller number than it.
 * For nums[2]=2 there exist one smaller number than it (1).
 * For nums[3]=2 there exist one smaller number than it (1).
 * For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [6,5,4,8]
 * Output: [2,1,0,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7]
 * Output: [0,0,0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 500
 * 0 <= nums[i] <= 100
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    auto sortedNums = nums;
    quickSort(sortedNums.begin(), sortedNums.end());

    for (auto i = 0; i < nums.size(); ++i) {
      res[i] = binarySearch(sortedNums.cbegin(), sortedNums.cend(), nums[i]) -
               sortedNums.cbegin();
    }

    return res;
  }

 private:
  // 快速排序
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

  // 二分查找：若找到，返回第一个指向该元素的迭代器；若未找到，返回 last
  template <typename It, typename T>
  It binarySearch(It first, It last, const T& target) {
    auto i = first;
    auto j = last;

    while (i < j) {
      auto mid = i + (j - i) / 2;

      if (*mid < target) {
        i = mid + 1;
      } else {
        j = mid;
      }
    }

    return (i != last && *i != target) ? last : i;
  }
};
// @lc code=end
