/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (58.44%)
 * Likes:    4511
 * Dislikes: 212
 * Total Accepted:    806.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<map<char, int>, vector<string>> groups;

    for (const auto& str : strs) {
      auto charCnt = map<char, int>();
      for (const auto& ch : str) {
        ++charCnt[ch];
      }

      groups[charCnt].push_back(str);
    }

    vector<vector<string>> res;
    for (const auto& p : groups) {
      res.push_back(p.second);
    }

    return res;
  }
};
// @lc code=end
