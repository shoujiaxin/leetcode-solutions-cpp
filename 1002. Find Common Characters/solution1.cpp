/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (67.52%)
 * Likes:    1084
 * Dislikes: 120
 * Total Accepted:    81.9K
 * Total Submissions: 120.9K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 *
 * You may return the answer in any order.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    array<int, 26> cnt{0};

    for (auto it = A.cbegin(); it != A.cend(); ++it) {
      decltype(cnt) temp{0};

      for (const auto& ch : *it) {
        ++temp[ch - 'a'];
      }

      if (it == A.cbegin()) {
        cnt = std::move(temp);
      } else {
        for (auto i = 0; i < 26; ++i) {
          cnt[i] = min(cnt[i], temp[i]);
        }
      }
    }

    vector<string> res;
    for (auto i = 0; i < 26; ++i) {
      while (cnt[i] > 0) {
        res.push_back(string(1, i + 'a'));
        --cnt[i];
      }
    }

    return res;
  }
};
// @lc code=end
