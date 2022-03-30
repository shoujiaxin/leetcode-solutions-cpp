/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (76.56%)
 * Likes:    1116
 * Dislikes: 347
 * Total Accepted:    173.2K
 * Total Submissions: 225.4K
 * Testcase Example:  '1\n22'
 *
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 *
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 *
 *
 * A self-dividing number is not allowed to contain the digit zero.
 *
 * Given two integers left and right, return a list of all the self-dividing
 * numbers in the range [left, right].
 *
 *
 * Example 1:
 * Input: left = 1, right = 22
 * Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
 * Example 2:
 * Input: left = 47, right = 85
 * Output: [48,55,66,77]
 *
 *
 * Constraints:
 *
 *
 * 1 <= left <= right <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (auto i = left; i <= right; ++i) {
      if (checkNumber(i)) {
        res.push_back(i);
      }
    }
    return res;
  }

 private:
  bool checkNumber(int num) {
    const auto str = to_string(num);
    for (const auto& ch : str) {
      const auto n = ch - '0';
      if (n == 0 || num % n != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
