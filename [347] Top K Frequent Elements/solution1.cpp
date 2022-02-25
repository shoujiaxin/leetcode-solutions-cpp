/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.35%)
 * Likes:    3612
 * Dislikes: 220
 * Total Accepted:    453.2K
 * Total Submissions: 737.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> cnt;
    for (const auto& n : nums) {
      ++cnt[n];
    }

    using Node = pair<int, int>;
    auto cmp = [](const Node& a, const Node& b) { return a.second < b.second; };

    priority_queue<Node, vector<Node>, decltype(cmp)> que(cmp);

    for (const auto& p : cnt) {
      que.push(p);
    }

    vector<int> res;
    for (auto i = 0; i < k; ++i) {
      res.push_back(que.top().first);
      que.pop();
    }

    return res;
  }
};
// @lc code=end
