/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (52.40%)
 * Likes:    723
 * Dislikes: 2192
 * Total Accepted:    273.8K
 * Total Submissions: 522.5K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: 3
 * Output: "III"
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "IV"
 *
 * Example 3:
 *
 *
 * Input: 9
 * Output: "IX"
 *
 * Example 4:
 *
 *
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */

// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    string str;

    while (num != 0) {
      if (1000 <= num) {
        str += "M";
        num -= 1000;
      } else if (900 <= num && num < 1000) {
        str += "CM";
        num -= 900;
      } else if (500 <= num && num < 900) {
        str += "D";
        num -= 500;
      } else if (400 <= num && num < 500) {
        str += "CD";
        num -= 400;
      } else if (100 <= num && num < 400) {
        str += "C";
        num -= 100;
      } else if (90 <= num && num < 100) {
        str += "XC";
        num -= 90;
      } else if (50 <= num && num < 90) {
        str += "L";
        num -= 50;
      } else if (40 <= num && num < 50) {
        str += "XL";
        num -= 40;
      } else if (10 <= num && num < 40) {
        str += "X";
        num -= 10;
      } else if (9 <= num && num < 10) {
        str += "IX";
        num -= 9;
      } else if (5 <= num && num < 9) {
        str += "V";
        num -= 5;
      } else if (4 <= num && num < 5) {
        str += "IV";
        num -= 4;
      } else if (1 <= num && num < 4) {
        str += "I";
        num -= 1;
      }
    }

    return str;
  }
};
// @lc code=end
