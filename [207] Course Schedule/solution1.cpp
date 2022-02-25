/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    4022
 * Dislikes: 181
 * Total Accepted:    433.3K
 * Total Submissions: 1M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegrees(numCourses, 0);                      // 节点入度
    vector<vector<int>> adjacency(numCourses, vector<int>());  // 节点的邻接节点
    queue<int> que;

    for (const auto& req : prerequisites) {
      auto cur = req.front();
      auto pre = req.back();  // 前置课程

      ++inDegrees[cur];
      adjacency[pre].push_back(cur);
    }

    // 入度为 0 的节点入队
    for (auto i = 0; i < numCourses; ++i) {
      if (inDegrees[i] == 0) {
        que.push(i);
      }
    }

    while (!que.empty()) {
      auto cur = que.front();
      que.pop();

      --numCourses;

      for (const auto& node : adjacency[cur]) {
        --inDegrees[node];
        if (inDegrees[node] == 0) {
          que.push(node);
        }
      }
    }

    return numCourses == 0;
  }
};
// @lc code=end
