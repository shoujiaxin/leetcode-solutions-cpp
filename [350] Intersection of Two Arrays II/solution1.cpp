/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (50.59%)
 * Likes:    1149
 * Dislikes: 366
 * Total Accepted:    313.4K
 * Total Submissions: 618.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    for (const auto& n : nums1) {
      ++m1[n];
    }

    for (const auto& n : nums2) {
      ++m2[n];
    }

    vector<int> res;
    for (const auto& p : m1) {
      for (auto i = 0; i < min(p.second, m2[p.first]); ++i) {
        res.push_back(p.first);
      }
    }

    return res;
  }
};
// @lc code=end
