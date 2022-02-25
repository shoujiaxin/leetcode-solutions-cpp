/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (52.91%)
 * Likes:    1392
 * Dislikes: 547
 * Total Accepted:    364.7K
 * Total Submissions: 689.2K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 *
 * Note:
 *
 *
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 *
 *
 * Example:
 *
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      if (numbers[left] + numbers[right] < target) {
        ++left;
      } else if (numbers[left] + numbers[right] > target) {
        --right;
      } else {
        // 返回的下标值（index1 和 index2）不是从零开始的
        return {left + 1, right + 1};
      }
    }

    return {0, 0};
  }
};
// @lc code=end
