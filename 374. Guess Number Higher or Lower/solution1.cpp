/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (41.78%)
 * Likes:    339
 * Dislikes: 1569
 * Total Accepted:    140.6K
 * Total Submissions: 336.2K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 *
 *
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 *
 *
 * Example :
 *
 *
 *
 * Input: n = 10, pick = 6
 * Output: 6
 *
 *
 *
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    auto lo = 1;
    auto hi = n;

    while (lo <= hi) {
      auto mid = lo + (hi - lo) / 2;

      auto res = guess(mid);
      if (res == 1) {
        lo = mid + 1;
      } else if (res == -1) {
        hi = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
// @lc code=end
