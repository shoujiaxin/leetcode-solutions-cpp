/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (28.45%)
 * Likes:    1988
 * Dislikes: 235
 * Total Accepted:    187K
 * Total Submissions: 650.7K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: "210"
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 */

// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    quickSort(nums.begin(), nums.end());

    string res;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
      if (res == "0") {
        res = "";
      }
      res += to_string(*it);
    }

    return res;
  }

 private:
  template <typename It>
  void quickSort(It first, It last) {
    if (first == last) {
      return;
    }

    auto pivot = *first;
    auto i = first;
    auto j = last - 1;

    while (i < j) {
      while (i < j && isGreaterOrEqual(*j, pivot)) {
        --j;
      }
      *i = *j;
      while (i < j && isLessOrEqual(*i, pivot)) {
        ++i;
      }
      *j = *i;
    }
    *i = pivot;

    quickSort(first, i);
    quickSort(i + 1, last);
  }

  bool isGreaterOrEqual(int num1, int num2) {
    auto str1 = to_string(num1);
    auto str2 = to_string(num2);
    return str1 + str2 >= str2 + str1;
  }

  bool isLessOrEqual(int num1, int num2) {
    auto str1 = to_string(num1);
    auto str2 = to_string(num2);
    return str1 + str2 <= str2 + str1;
  }
};
// @lc code=end
