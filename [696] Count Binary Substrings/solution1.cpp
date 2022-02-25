/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (55.75%)
 * Likes:    994
 * Dislikes: 168
 * Total Accepted:    46.5K
 * Total Submissions: 83K
 * Testcase Example:  '"00110"'
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in
 * these substrings are grouped consecutively.
 *
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 *
 * Example 1:
 *
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 *
 *
 *
 * Example 2:
 *
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 *
 *
 *
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
 *
 */

// @lc code=start
class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> groupedNumbers;  // 连续字符的个数

    // 统计连续字符的个数
    // 如："111100011000"，groupedNumbers 为 {4, 3, 2, 3}
    auto last = s.front();
    auto cnt = 0;
    for (const auto& ch : s) {
      if (ch == last) {
        ++cnt;
      } else {
        groupedNumbers.push_back(cnt);
        last = ch;
        cnt = 1;
      }
    }
    groupedNumbers.push_back(cnt);

    // 取 groupedNumbers 相邻元素中较小的求和
    auto res = 0;
    for (auto it = groupedNumbers.cbegin() + 1; it < groupedNumbers.cend();
         ++it) {
      res += min(*(it - 1), *it);
    }

    return res;
  }
};
// @lc code=end
