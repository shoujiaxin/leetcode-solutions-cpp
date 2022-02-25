/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 *
 * https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
 *
 * algorithms
 * Easy (46.27%)
 * Likes:    654
 * Dislikes: 1681
 * Total Accepted:    101K
 * Total Submissions: 218.3K
 * Testcase Example:  '[1,0,0]'
 *
 * We have two special characters:
 *
 *
 * The first character can be represented by one bit 0.
 * The second character can be represented by two bits (10 or 11).
 *
 *
 * Given a binary array bits that ends with 0, return true if the last
 * character must be a one-bit character.
 *
 *
 * Example 1:
 *
 *
 * Input: bits = [1,0,0]
 * Output: true
 * Explanation: The only way to decode it is two-bit character and one-bit
 * character.
 * So the last character is one-bit character.
 *
 *
 * Example 2:
 *
 *
 * Input: bits = [1,1,1,0]
 * Output: false
 * Explanation: The only way to decode it is two-bit character and two-bit
 * character.
 * So the last character is not one-bit character.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= bits.length <= 1000
 * bits[i] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    if (bits.size() == 1) {
      return true;
    }

    auto cnt = 0;
    for (auto it = bits.rbegin() + 1; it < bits.rend() && *it == 1; ++it) {
      ++cnt;
    }

    return cnt % 2 == 0;
  }
};
// @lc code=end
