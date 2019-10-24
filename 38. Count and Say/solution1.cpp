/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (42.02%)
 * Likes:    924
 * Dislikes: 7363
 * Total Accepted:    324.6K
 * Total Submissions: 772.1K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 */

// @lc code=start
class Solution {
 public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }

    auto str = countAndSay(n - 1);
    string result;

    auto ch = str.front();
    int cnt = 0;
    for (const auto &c : str) {
      if (c == ch) {
        ++cnt;
      } else {
        result.append(to_string(cnt));
        result.push_back(ch);
        ch = c;
        cnt = 1;
      }
    }

    result.append(to_string(cnt));
    result.push_back(ch);

    return result;
  }
};
// @lc code=end
