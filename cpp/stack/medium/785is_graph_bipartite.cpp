/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (49.12%)
 * Likes:    2859
 * Dislikes: 235
 * Total Accepted:    211K
 * Total Submissions: 429.7K
 * Testcase Example:  '[[1,2,3],[0,2],[0,1,3],[0,2]]'
 *
 * There is an undirected graph with n nodes, where each node is numbered
 * between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
 * array of nodes that node u is adjacent to. More formally, for each v in
 * graph[u], there is an undirected edge between node u and node v. The graph
 * has the following properties:
 *
 *
 * There are no self-edges (graph[u] does not contain u).
 * There are no parallel edges (graph[u] does not contain duplicate
 * values).
 * If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * The graph may not be connected, meaning there may be two nodes u and v such
 * that there is no path between them.
 *
 *
 * A graph is bipartite if the nodes can be partitioned into two independent
 * sets A and B such that every edge in the graph connects a node in set A and
 * a node in set B.
 *
 * Return true if and only if it is bipartite.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * Output: false
 * Explanation: There is no way to partition the nodes into two independent
 * sets such that every edge connects a node in one and a node in the other.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 * Output: true
 * Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 *
 *
 * Constraints:
 *
 *
 * graph.length == n
 * 1 <= n <= 100
 * 0 <= graph[u].length < n
 * 0 <= graph[u][i] <= n - 1
 * graph[u] does not contain u.
 * All the values of graph[u] are unique.
 * If graph[u] contains v, then graph[v] contains u.
 *
 *
 */

// @lc code=start
// Coloring
class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    for (std::size_t i = 0; i < graph.size(); ++i) {
      if (color[i] == -1 && !dfs(i, 0, color, graph)) return false;
    }
    return true;
  }

 private:
  bool dfs(int cur_node, int cur_color, vector<int>& color,
           vector<vector<int>>& graph) {
    color[cur_node] = cur_color;
    for (auto next_node : graph[cur_node]) {
      if (color[next_node] == -1 && !dfs(next_node, !cur_color, color, graph)) {
        return false;
      } else {
        if (color[next_node] == cur_color) return false;
      }
    }
    return true;
  }
};
// @lc code=end
