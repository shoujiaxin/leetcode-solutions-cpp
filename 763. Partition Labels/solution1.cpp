/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (75.38%)
 * Likes:    3446
 * Dislikes: 140
 * Total Accepted:    190.8K
 * Total Submissions: 246.3K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * A string S of lowercase English letters is given. We want to partition this
 * string into as many parts as possible so that each letter appears in at most
 * one part, and return a list of integers representing the size of these
 * parts.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 *
 *
 *
 *
 * Note:
 *
 *
 * S will have length in range [1, 500].
 * S will consist of lowercase English letters ('a' to 'z') only.
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    array<int, 26> last{0};  // 字母最后一次出现的下标
    for (auto i = 0; i < S.size(); ++i) {
      last[S[i] - 'a'] = i;
    }

    vector<int> res;
    auto begin = 0;
    auto end = 0;

    for (auto i = 0; i < S.size(); ++i) {
      end = max(end, last[S[i] - 'a']);
      if (i == end) {
        res.push_back(end - begin + 1);
        begin = end + 1;
      }
    }

    return res;
  }
};
// @lc code=end
