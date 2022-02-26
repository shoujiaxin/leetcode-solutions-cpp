/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (70.92%)
 * Likes:    479
 * Dislikes: 1106
 * Total Accepted:    79.6K
 * Total Submissions: 112.1K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * A complex number can be represented as a string on the form
 * "real+imaginaryi" where:
 *
 *
 * real is the real part and is an integer in the range [-100, 100].
 * imaginary is the imaginary part and is an integer in the range [-100,
 * 100].
 * i^2 == -1.
 *
 *
 * Given two complex numbers num1 and num2 as strings, return a string of the
 * complex number that represents their multiplications.
 *
 *
 * Example 1:
 *
 *
 * Input: num1 = "1+1i", num2 = "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 *
 *
 * Example 2:
 *
 *
 * Input: num1 = "1+-1i", num2 = "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 *
 *
 *
 * Constraints:
 *
 *
 * num1 and num2 are valid complex numbers.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string complexNumberMultiply(string num1, string num2) {
    int a1, b1, a2, b2;
    tie(a1, b1) = getRealAndImaginary(num1);
    tie(a2, b2) = getRealAndImaginary(num2);

    auto a = a1 * a2 - b1 * b2;
    auto b = a1 * b2 + a2 * b1;
    return to_string(a) + "+" + to_string(b) + "i";
  }

 private:
  tuple<int, int> getRealAndImaginary(const string& num) {
    auto it = find(num.cbegin(), num.cend(), '+');
    auto realStr = string(num.cbegin(), it);
    auto imaginaryStr = string(it + 1, num.cend() - 1);
    return make_tuple(stoi(realStr), stoi(imaginaryStr));
  }
};
// @lc code=end
