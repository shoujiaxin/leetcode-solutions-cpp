/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    1325
 * Dislikes: 3951
 * Total Accepted:    395.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    if (s.size() < 2 || numRows == 1) {
      return s;
    }

    std::vector<std::vector<short>> m;
    m.resize(numRows);
    for (auto& v : m) {
      v.resize(std::ceil(static_cast<double>(s.size()) / (2 * numRows - 2)) *
               (numRows - 1));
    }

    auto row = 0, col = 0, cnt = 0;

    for (auto it = s.cbegin(); it != s.cend();) {
      if (cnt < numRows) {
        m[row][col] = *it;
        ++row;
        ++cnt;
        ++it;
      } else if (cnt < 2 * numRows - 2) {
        if (cnt == numRows) {
          --row;
        }
        --row;
        ++col;
        m[row][col] = *it;
        ++cnt;
        ++it;
      } else {
        row = (numRows == 2) ? 0 : row - 1;
        ++col;
        cnt = 0;
      }
    }

    std::string str = "";
    for (const auto& v : m) {
      for (const auto& c : v) {
        if (c != 0) {
          str.push_back(c);
        }
      }
    }

    return str;
  }
};
// @lc code=end
