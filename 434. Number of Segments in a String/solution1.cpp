/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.49%)
 * Likes:    193
 * Dislikes: 690
 * Total Accepted:    71.6K
 * Total Submissions: 191K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int cnt = 0;

    istringstream istm(s);
    string word;
    while (istm >> word) {
      ++cnt;
    }

    return cnt;
  }
};
// @lc code=end
