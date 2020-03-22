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
    auto nums = merge(nums1, nums2);
    auto len = nums.size();

    if (len % 2) {
      return nums[len / 2];
    } else {
      return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;
    }
  }

 private:
  vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
    auto len1 = nums1.size();
    auto len2 = nums2.size();

    vector<int> res(len1 + len2, 0);
    auto it = res.begin();
    auto it1 = nums1.cbegin();
    auto it2 = nums2.cbegin();

    while (it1 != nums1.cend() || it2 != nums2.cend()) {
      if (it1 == nums1.cend()) {
        *it = *it2;
        ++it2;
      } else if (it2 == nums2.cend()) {
        *it = *it1;
        ++it1;
      } else {
        if (*it1 < *it2) {
          *it = *it1;
          ++it1;
        } else {
          *it = *it2;
          ++it2;
        }
      }
      ++it;
    }

    return res;
  }
};
// @lc code=end
