/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (50.07%)
 * Likes:    1830
 * Dislikes: 390
 * Total Accepted:    452.5K
 * Total Submissions: 904.3K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Return True if n is a happy number, and False if not.
 *
 * Example: 
 *
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    auto numStr = to_string(n);

    // 保存所有平方求和所得的数字，如果出现相同的，则无限循环
    unordered_set<string> nums;

    while (nums.find(numStr) == nums.end()) {
      if (numStr == "1") {
        return true;
      }

      nums.insert(numStr);

      auto val = 0;
      for (const auto& c : numStr) {
        val += (c - '0') * (c - '0');
      }
      numStr = to_string(val);
    }

    return false;
  }
};
// @lc code=end
