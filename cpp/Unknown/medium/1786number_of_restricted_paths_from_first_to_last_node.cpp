/*
 * @lc app=leetcode id=1786 lang=cpp
 *
 * [1786] Number of Restricted Paths From First to Last Node
 *
 * https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    161
 * Dislikes: 30
 * Total Accepted:    4K
 * Total Submissions: 11.3K
 * Testcase Example:  '5\n[[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]'
 *
 * There is an undirected weighted connected graph. You are given a positive
 * integer n which denotes that the graph has n nodes labeled from 1 to n, and
 * an array edges where each edges[i] = [ui, vi, weighti] denotes that there is
 * an edge between nodes ui and vi with weight equal to weighti.
 * 
 * A path from node start to node end is a sequence of nodes [z0, z1, z2, ...,
 * zk] such that z0 = start and zk = end and there is an edge between zi and
 * zi+1 where 0 <= i <= k-1.
 * 
 * The distance of a path is the sum of the weights on the edges of the path.
 * Let distanceToLastNode(x) denote the shortest distance of a path between
 * node n and node x. A restricted path is a path that also satisfies that
 * distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
 * 
 * Return the number of restricted paths from node 1 to node n. Since that
 * number may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, edges =
 * [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
 * Output: 3
 * Explanation: Each circle contains the node number in black and its
 * distanceToLastNode value in blue. The three restricted paths are:
 * 1) 1 --> 2 --> 5
 * 2) 1 --> 2 --> 3 --> 5
 * 3) 1 --> 3 --> 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7, edges =
 * [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
 * Output: 1
 * Explanation: Each circle contains the node number in black and its
 * distanceToLastNode value in blue. The only restricted path is 1 --> 3 -->
 * 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2 * 10^4
 * n - 1 <= edges.length <= 4 * 10^4
 * edges[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 1 <= weighti <= 10^5
 * There is at most one edge between any two nodes.
 * There is at least one path between any two nodes.
 * 
 * 
 */
// Graph + DP
// Run Dijkstra from n:
// dist[u] : distance from u to n; cnt[u] : number of rpath from u to n;
// for each node u visited:
//     update cnt[u] = sum of cnt[v] where v is neighbor of u && dist[u] > dist[v]
// return cnt[0]
// TODO: Revisit after graph algorithms learned.
// @lc code=start
class Solution {
    using PII = pair<int, int>;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        const int MOD = 1e9 + 7;
        vector<vector<PII>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<int> dist(n + 1, INT_MAX), cnt(n + 1, 0);
        dist[n] = 0;
        cnt[n] = 1;
        pq.emplace(0, n);

        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dist[u]) continue;
            for (auto& [v, d] : g[u]) {
                if (dist[v] > w + d) {
                    dist[v] = w + d;
                    pq.emplace(dist[v], v);
                }
                if (w > dist[v]) {
                    cnt[u] = (cnt[u] + cnt[v]) % MOD;
                }
            }
        }
        return cnt[1];
    }
};
// @lc code=end

