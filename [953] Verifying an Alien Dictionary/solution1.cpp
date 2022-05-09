/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (52.53%)
 * Likes:    2797
 * Dislikes: 929
 * Total Accepted:    349.2K
 * Total Submissions: 664.8K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly, they also use English lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographically in this alien language.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    for (auto i = 0; i < 26; ++i) {
      dict[order[i] - 'a'] = i;
    }

    for (auto i = 0; i < words.size() - 1; ++i) {
      if (cmp(words[i], words[i + 1]) > 0) {
        return false;
      }
    }
    return true;
  }

 private:
  array<int, 26> dict;

  int cmp(const string_view& s1, const string_view& s2) {
    auto it1 = s1.cbegin();
    auto it2 = s2.cbegin();

    while (it1 < s1.cend() || it2 < s2.cend()) {
      if (it1 == s1.cend()) {
        return -1;
      }
      if (it2 == s2.cend()) {
        return 1;
      }

      const auto idx1 = dict[*it1 - 'a'];
      const auto idx2 = dict[*it2 - 'a'];
      if (idx1 < idx2) {
        return -1;
      }
      if (idx1 > idx2) {
        return 1;
      }
      ++it1;
      ++it2;
    }

    return 0;
  }
};
// @lc code=end
