/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (36.33%)
 * Likes:    2006
 * Dislikes: 1036
 * Total Accepted:    168.4K
 * Total Submissions: 457.6K
 * Testcase Example: '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 *
 * Note:
 *
 *
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * One must use all the tickets once and only once.
 *
 *
 * Example 1:
 *
 *
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  // 使用最小堆存储每个出发点对应的到达点
  using Map = unordered_map<
      string, priority_queue<string, vector<string>, std::greater<string>>>;

  vector<string> findItinerary(vector<vector<string>>& tickets) {
    Map m;
    for (const auto& ticket : tickets) {
      m[ticket.front()].emplace(ticket.back());
    }

    dfs(m, "JFK");

    reverse(res.begin(), res.end());

    return res;
  }

 private:
  vector<string> res;

  void dfs(Map& m, const string& s) {
    while (m.count(s) && m[s].size() > 0) {
      auto temp = m[s].top();
      m[s].pop();

      dfs(m, temp);
    }

    // 逆序插入结果，最后走 “死胡同“
    res.emplace_back(s);
  }
};
// @lc code=end
