/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 *
 * https://leetcode.com/problems/find-center-of-star-graph/description/
 *
 * algorithms
 * Medium (86.43%)
 * Likes:    24
 * Dislikes: 26
 * Total Accepted:    5.9K
 * Total Submissions: 6.8K
 * Testcase Example:  '[[1,2],[2,3],[4,2]]'
 *
 * There is an undirected star graph consisting of n nodes labeled from 1 to n.
 * A star graph is a graph where there is one center node and exactly n - 1
 * edges that connect the center node with every other node.
 * 
 * You are given a 2D integer array edges where each edges[i] = [ui, vi]
 * indicates that there is an edge between the nodes ui and vi. Return the
 * center of the given star graph.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[1,2],[2,3],[4,2]]
 * Output: 2
 * Explanation: As shown in the figure above, node 2 is connected to every
 * other node, so 2 is the center.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[1,2],[5,1],[1,3],[1,4]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 * ui != vi
 * The given edges represent a valid star graph.
 * 
 */

// @lc code=start
// O(1)
// Since the center node has to appear in every edge
// Only need to find the node appeared in both edge 1 and edge 2
class Solution {
public:
    int findCenter(vector<vector<int>>& e)
    {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};
// @lc code=end

// O(n)
// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int sz = edges.size();
//         vector<int> cnt(sz + 2, 0);
//         for (const auto& e : edges) {
//             int u = e[0], v = e[1];
//             ++cnt[u];
//             ++cnt[v];
//         }
//         for (int i = 1; i < cnt.size(); ++i) {
//             if (cnt[i] == sz) return i;
//         }
//         return 0;
//     }
// };
