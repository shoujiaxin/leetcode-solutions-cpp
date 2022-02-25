/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.55%)
 * Likes:    5227
 * Dislikes: 760
 * Total Accepted:    526.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto len1 = nums1.size();
    auto len2 = nums2.size();

    auto len = len1 + len2;

    if (len % 2) {
      return getKthMin(nums1, 0, len1 - 1, nums2, 0, len2 - 1, len / 2 + 1);
    } else {
      return (getKthMin(nums1, 0, len1 - 1, nums2, 0, len2 - 1, len / 2) +
              getKthMin(nums1, 0, len1 - 1, nums2, 0, len2 - 1, len / 2 + 1)) /
             2.0;
    }
  }

 private:
  /// 获取有序数组 nums1 和 nums2 中第 k 小的元素
  /// @param nums1 有序数组
  /// @param begin1 起始位置
  /// @param end1 终止位置
  /// @param nums2 有序数组
  /// @param begin2 起始位置
  /// @param end2 终止位置
  /// @param k 序号
  int getKthMin(const vector<int>& nums1, int begin1, int end1,
                const vector<int>& nums2, int begin2, int end2, int k) {
    auto len1 = end1 - begin1 + 1;
    auto len2 = end2 - begin2 + 1;

    // 确保 nums1 更短，有一数组为空时，必为 nums1
    if (len1 > len2) {
      return getKthMin(nums2, begin2, end2, nums1, begin1, end1, k);
    }

    // nums1 为空，返回 nums2 中第 k 小的元素
    if (len1 == 0) {
      return nums2[begin2 + k - 1];
    }

    // 递归出口，返回两个有序数组的最小元素
    if (k == 1) {
      return min(nums1[begin1], nums2[begin2]);
    }

    // 二分查找，每次比较 k / 2 位置上的元素
    int i = begin1 + min(len1, k / 2) - 1;
    int j = begin2 + min(len2, k / 2) - 1;

    // 舍去更小者及其前面的所有元素，减小 k 并缩小数组范围
    if (nums1[i] > nums2[j]) {
      return getKthMin(nums1, begin1, end1, nums2, j + 1, end2,
                       k - (j - begin2 + 1));
    } else {
      return getKthMin(nums1, i + 1, end1, nums2, begin2, end2,
                       k - (i - begin1 + 1));
    }
  }
};
// @lc code=end
