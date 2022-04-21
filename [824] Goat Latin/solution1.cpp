/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 *
 * https://leetcode.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (67.34%)
 * Likes:    675
 * Dislikes: 1088
 * Total Accepted:    141.6K
 * Total Submissions: 209.6K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * You are given a string sentence that consist of words separated by spaces.
 * Each word consists of lowercase and uppercase letters only.
 *
 * We would like to convert the sentence to "Goat Latin" (a made-up language
 * similar to Pig Latin.) The rules of Goat Latin are as follows:
 *
 *
 * If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to
 * the end of the word.
 *
 *
 * For example, the word "apple" becomes "applema".
 *
 *
 * If a word begins with a consonant (i.e., not a vowel), remove the first
 * letter and append it to the end, then add "ma".
 *
 * For example, the word "goat" becomes "oatgma".
 *
 *
 * Add one letter 'a' to the end of each word per its word index in the
 * sentence, starting with 1.
 *
 * For example, the first word gets "a" added to the end, the second word gets
 * "aa" added to the end, and so on.
 *
 *
 *
 *
 * Return the final sentence representing the conversion from sentence to Goat
 * Latin.
 *
 *
 * Example 1:
 * Input: sentence = "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * Example 2:
 * Input: sentence = "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 *
 *
 * Constraints:
 *
 *
 * 1 <= sentence.length <= 150
 * sentence consists of English letters and spaces.
 * sentence has no leading or trailing spaces.
 * All the words in sentence are separated by a single space.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string toGoatLatin(string sentence) {
    string res;

    auto l = 0;
    auto r = 0;
    auto index = 1;
    while (r < sentence.size()) {
      while (isalpha(sentence[r])) {
        ++r;
      }

      auto word = sentence.substr(l, r - l);
      if (!startsWithVowel(word)) {
        word = word.substr(1, word.size() - 1) + word[0];
      }

      res += word + "ma" + string(index, 'a') + " ";

      ++r;
      l = r;
      ++index;
    }

    res.pop_back();

    return res;
  }

 private:
  bool startsWithVowel(const string_view& word) {
    const auto& ch = tolower(word[0]);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
};
// @lc code=end
