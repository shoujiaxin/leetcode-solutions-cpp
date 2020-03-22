/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.80%)
 * Likes:    629
 * Dislikes: 4347
 * Total Accepted:    155.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 *
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 *
 *
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 *
 *
 * Of course, the context of these characters also matters in the input.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 *
 */

// @lc code=start
class Solution {
 public:
  bool isNumber(string s) {
    auto b = s.find_first_not_of(' ');
    if (b == string::npos) {
      return false;
    }

    auto e = s.find_last_not_of(' ');

    auto numStr = s.substr(b, e - b + 1);
    if (s.empty()) {
      return false;
    }

    auto pos = numStr.find('e');
    if (pos == string::npos) {
      return checkBase(numStr);
    } else {
      return checkBase(numStr.substr(0, pos)) &&
             checkExp(numStr.substr(pos + 1));
    }
  }

 private:
  /// 检查底数的合法性
  /// @param str 底数字符串
  bool checkBase(const string& str) {
    if (str.empty()) {
      return false;
    }

    bool point = false;  // 是否包含小数点
    bool res = false;    // 是否合法，避免只有一个小数点的情况

    for (auto it = str.cbegin(); it != str.cend(); ++it) {
      if (*it == '+' || *it == '-') {
        if (it != str.cbegin()) {
          return false;  // 正负号不在首位
        }
      } else if (*it == '.') {
        if (point) {
          return false;  // 包含多个小数点
        }
        point = true;
      } else if (!isdigit(*it)) {
        return false;  // 不是数字
      } else {
        res = true;
      }
    }

    return res;
  }

  /// 检查指数的合法性
  /// @param str 指数字符串
  bool checkExp(const string& str) {
    if (str.empty()) {
      return false;
    }

    bool res = false;  // 是否合法，避免只有一个正/负号的情况

    for (auto it = str.cbegin(); it != str.cend(); ++it) {
      if (*it == '+' || *it == '-') {
        if (it != str.cbegin()) {
          return false;  // 正负号不在首位
        }
      } else if (*it == '.') {
        return false;  // 指数不能包含小数点
      } else if (!isdigit(*it)) {
        return false;  // 不是数字
      } else {
        res = true;
      }
    }

    return res;
  }
};
// @lc code=end
