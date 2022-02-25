/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (71.35%)
 * Likes:    419
 * Dislikes: 18
 * Total Accepted:    55.5K
 * Total Submissions: 77.5K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, write a function that returns true if and
 * only if the number of occurrences of each value in the array is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for (const auto& n : arr) {
      ++cnt[n];
    }

    unordered_set<int> nums;
    for (const auto& p : cnt) {
      if (nums.find(p.second) != nums.end()) {
        return false;
      }

      nums.insert(p.second);
    }

    return true;
  }
};
// @lc code=end
