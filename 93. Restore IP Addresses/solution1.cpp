/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    1273
 * Dislikes: 502
 * Total Accepted:    194.9K
 * Total Submissions: 551K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * A valid IP address consists of exactly four integers (each integer is
 * between 0 and 255) separated by single points.
 *
 * Example:
 *
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    // 每个整数最多 3 位
    if (s.size() > 12) {
      return {};
    }

    backtrack(s, "", 0, 0);
    return res;
  }

 private:
  vector<string> res;

  void backtrack(const string& s, string path, int depth, int dotCnt) {
    // 末尾多一个 '.'
    if (dotCnt == 4 && depth == s.size()) {
      path.pop_back();
      res.push_back(path);
      return;
    }

    // 每一个整数为 1～3 位
    for (auto i = 1; i < 4; ++i) {
      if (depth + i > s.size()) {
        break;  // 到末尾，超出范围
      }

      if (i > 1 && s[depth] == '0') {
        break;  // 以 0 开头的 2、3 位数，不合法
      }

      auto numStr = s.substr(depth, i);
      if (stoi(numStr) > 255) {
        break;
      }

      backtrack(s, path + numStr + ".", depth + i, dotCnt + 1);
    }
  }
};
// @lc code=end
