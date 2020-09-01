/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (64.40%)
 * Likes:    784
 * Dislikes: 1060
 * Total Accepted:    62.7K
 * Total Submissions: 96.4K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alex and Lee play a game with piles of stones.  There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 *
 * The objective of the game is to end with the most stones.  The total number
 * of stones is odd, so there are no ties.
 *
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player
 * takes the entire pile of stones from either the beginning or the end of the
 * row.  This continues until there are no more piles left, at which point the
 * person with the most stones wins.
 *
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins
 * the game.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation:
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10
 * points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we
 * return true.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    auto len = piles.size();

    // dp[i][j] 表示数组剩下 i 到 j 的元素时，两个玩家的最大分差
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (auto i = 0; i < len; ++i) {
      dp[i][i] = piles[i];
    }

    for (int i = len - 2; i >= 0; --i) {
      for (auto j = i + 1; j < len; ++j) {
        // 当前玩家可选择 nums[i] 或 nums[j]
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }
    }

    return dp[0][len - 1] > 0;
  }
};
// @lc code=end
