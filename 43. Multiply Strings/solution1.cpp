/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.75%)
 * Likes:    1515
 * Dislikes: 700
 * Total Accepted:    266.5K
 * Total Submissions: 810.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 *
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 *
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 *
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1.size() < num2.size()) {
      return multiply(num2, num1);
    }
    if (num2 == "0") {
      return num2;
    } else if (num2 == "1") {
      return num1;
    }

    string res = "0";

    for (auto it2 = num2.rbegin(); it2 != num2.rend(); ++it2) {
      string temp(it2 - num2.rbegin(), '0');
      auto n = 0;  // 进位

      for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1) {
        auto val = (*it1 - '0') * (*it2 - '0') + n;
        n = val / 10;
        val %= 10;
        temp.push_back(val + '0');
      }
      if (n != 0) {
        temp.push_back(n + '0');
      }

      reverse(temp.begin(), temp.end());
      res = add(res, temp);
    }

    return res;
  }

 private:
  string add(const string& num1, const string& num2) {
    auto len1 = num1.size();
    auto len2 = num2.size();
    string res(max(len1, len2) + 1, '0');

    auto it = res.rbegin();
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    while (it1 != num1.rend() || it2 != num2.rend()) {
      auto val = *it - '0';

      if (it1 != num1.rend()) {
        val += *it1 - '0';
        ++it1;
      }
      if (it2 != num2.rend()) {
        val += *it2 - '0';
        ++it2;
      }

      if (val > 9) {
        *(it + 1) = '1';
        val -= 10;
      }
      *it = val + '0';
      ++it;
    }

    return (res.front() == '0') ? res.substr(1) : res;
  }
};
// @lc code=end
