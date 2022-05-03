/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (55.98%)
 * Likes:    1661
 * Dislikes: 3884
 * Total Accepted:    295.3K
 * Total Submissions: 527.4K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]'
 *
 * You are given an array of logs. Each log is a space-delimited string of
 * words, where the first word is the identifier.
 *
 * There are two types of logs:
 *
 *
 * Letter-logs: All words (except the identifier) consist of lowercase English
 * letters.
 * Digit-logs: All words (except the identifier) consist of digits.
 *
 *
 * Reorder these logs so that:
 *
 *
 * The letter-logs come before all digit-logs.
 * The letter-logs are sorted lexicographically by their contents. If their
 * contents are the same, then sort them lexicographically by their
 * identifiers.
 * The digit-logs maintain their relative ordering.
 *
 *
 * Return the final order of the logs.
 *
 *
 * Example 1:
 *
 *
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * Explanation:
 * The letter-log contents are all different, so their ordering is "art can",
 * "art zero", "own kit dig".
 * The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
 *
 *
 * Example 2:
 *
 *
 * Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act
 * zoo"]
 * Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4
 * 7"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * All the tokens of logs[i] are separated by a single space.
 * logs[i] is guaranteed to have an identifier and at least one word after the
 * identifier.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    const auto& decouple = [](const std::string_view& log)
        -> std::tuple<std::string_view, std::string_view> {
      const auto pos = log.find_first_of(' ');
      return std::make_tuple(log.substr(0, pos), log.substr(pos + 1));
    };

    stable_sort(
        logs.begin(), logs.end(),
        [&](const std::string_view& log1, const std::string_view& log2) {
          const auto isDigit1 = isdigit(log1.back());
          const auto isDigit2 = isdigit(log2.back());

          if (isDigit1 && isDigit2) {
            return false;
          } else if (isDigit1) {
            return false;
          } else if (isDigit2) {
            return true;
          }

          const auto& [identifier1, content1] = decouple(log1);
          const auto& [identifier2, content2] = decouple(log2);

          return content1 < content2 ||
                 (content1 == content2 && identifier1 < identifier2);
        });

    return logs;
  }
};
// @lc code=end
