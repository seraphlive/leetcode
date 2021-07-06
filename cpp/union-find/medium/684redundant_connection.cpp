/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (59.82%)
 * Likes:    2590
 * Dislikes: 265
 * Total Accepted:    153.8K
 * Total Submissions: 257.1K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 *
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 *
 *
 *
 * Constraints:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 *
 *
 */

// @lc code=start
// Union find. For each pair of nodes, if they are not in the same set (tree)
// yet, merge them, i.e. draw (use) this edge. If they are already in the same
// set, the edge is redundant.
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> p(edges.size() + 1);
    for (std::size_t i = 1; i <= edges.size(); ++i) p[i] = i;

    for (auto& e : edges) {
      int u = e[0], v = e[1];
      if (find(u, p) == find(v, p)) return e;
      merge(u, v, p);
    }
    return {-1, -1};
  }

 private:
  int find(int a, vector<int>& p) {
    if (p[a] != a) p[a] = find(p[a], p);
    return p[a];
  }

  void merge(int a, int b, vector<int>& p) {
    if (find(a, p) == find(b, p)) return;
    p[find(a, p)] = p[find(b, p)];
  }
};
// @lc code=end
