/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    6336
 * Dislikes: 269
 * Total Accepted:    621.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

// @lc code=start
// Topologic order is valid only when there is no cycle in the graph.
class Solution {
 public:
  bool canFinish(int n, vector<vector<int>>& pr) {
    vector<vector<int>> adj(n, vector<int>{});
    vector<int> degree(n, 0);
    for (auto& p : pr) {
      adj[p[1]].push_back(p[0]);
      ++degree[p[0]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (degree[i] == 0) q.push(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      --n;
      for (auto ne : adj[cur])
        if (--degree[ne] == 0) q.push(ne);
    }
    return n == 0;
  }
};
// @lc code=end
