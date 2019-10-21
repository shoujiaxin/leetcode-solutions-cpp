/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.83%)
 * Likes:    1134
 * Dislikes: 7031
 * Total Accepted:    431K
 * Total Submissions: 2.9M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *
 *
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 *
 *
 * Example 1:
 *
 *
 * Input: "42"
 * Output: 42
 *
 *
 * Example 2:
 *
 *
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 *
 *
 * Example 3:
 *
 *
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 *
 *
 * Example 4:
 *
 *
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 *
 * Example 5:
 *
 *
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 *
 */

// @lc code=start
class Solution {
 public:
  int myAtoi(string str) {
    long int number = 0;
    auto begin = find_if(str.cbegin(), str.cend(),
                         [](const char& c) { return !isspace(c); });
    if (isalpha(*begin) || *begin == '.') {
      return 0;  // "  abc123"
    } else if (*begin == '+' || *begin == '-') {
      if (begin == str.cend() || !isdigit(*(begin + 1))) {
        return 0;  // "+-2"
      }
    }

    auto end = find_if(begin + 1, str.cend(),
                       [](const char& c) { return !isdigit(c); });
    auto numberBegin = find_if(
        begin, str.cend(), [](const char& c) { return '1' <= c && c <= '9'; });
    if (distance(numberBegin, end) > 10) {
      return *begin == '-' ? -INT_MAX - 1 : INT_MAX;
    }

    for (auto iter = begin; iter != end; ++iter) {
      if (!isdigit(*iter)) {
        continue;
      }

      number *= 10;
      number += *iter - '0';
    }

    number = *begin == '-' ? -number : number;
    if (static_cast<int>(number) != number) {
      return number > 0 ? INT_MAX : -INT_MAX - 1;
    }

    return number;
  }
};
// @lc code=end
