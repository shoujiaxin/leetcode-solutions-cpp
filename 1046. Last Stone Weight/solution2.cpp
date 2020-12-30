/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 *
 * https://leetcode.com/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (62.42%)
 * Likes:    1114
 * Dislikes: 33
 * Total Accepted:    154.6K
 * Total Submissions: 247.6K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * We have a collection of stones, each stone has a positive integer weight.
 *
 * Each turn, we choose the two heaviest stones and smash them together.
 * Suppose the stones have weights x and y with x <= y.  The result of this
 * smash is:
 *
 *
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of
 * weight y has new weight y-x.
 *
 *
 * At the end, there is at most 1 stone left.  Return the weight of this stone
 * (or 0 if there are no stones left.)
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 * we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 * we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we combine 1 and 1 to get 0 so the array converts to [1] then that's the
 * value of last stone.
 *
 *
 *
 * Note:
 *
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lastStoneWeight(vector<int> &stones) {
    auto que = priority_queue<int, std::vector<int>, std::less<int>>();
    for (const auto stone : stones) {
      que.push(stone);
    }

    while (que.size() >= 2) {
      auto x = que.top();
      que.pop();
      auto y = que.top();
      que.pop();

      if (x > y) {
        que.push(x - y);
      }
    }

    return que.size() == 1 ? que.top() : 0;
  }
};
// @lc code=end
