/*
 * @lc app=leetcode id=1782 lang=cpp
 *
 * [1782] Count Pairs Of Nodes
 *
 * https://leetcode.com/problems/count-pairs-of-nodes/description/
 *
 * algorithms
 * Hard (25.89%)
 * Likes:    69
 * Dislikes: 40
 * Total Accepted:    1.2K
 * Total Submissions: 4.5K
 * Testcase Example:  '4\n[[1,2],[2,4],[1,3],[2,3],[2,1]]\n[2,3]'
 *
 * You are given an undirected graph represented by an integer n, which is the
 * number of nodes, and edges, where edges[i] = [ui, vi] which indicates that
 * there is an undirected edge between ui and vi. You are also given an integer
 * array queries.
 * 
 * The answer to the j^th query is the number of pairs of nodes (a, b) that
 * satisfy the following conditions:
 * 
 * 
 * a < b
 * cnt is strictly greater than queries[j], where cnt is the number of edges
 * incident to a or b.
 * 
 * 
 * Return an array answers such that answers.length == queries.length and
 * answers[j] is the answer of the j^th query.
 * 
 * Note that there can be repeated edges.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
 * Output: [6,5]
 * Explanation: The number of edges incident to at least one of each pair is
 * shown above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]],
 * queries = [1,2,3,4,5]
 * Output: [10,10,9,8,6]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 2 * 10^4
 * 1 <= edges.length <= 10^5
 * 1 <= ui, vi <= n
 * ui != vi
 * 1 <= queries.length <= 20
 * 0 <= queries[j] < edges.length
 * 
 * 
 */

// for q in queries:
//     point a, b: (a<b: no duplicate count in answer)
//     find d[a]+d[b]-emap[a,b] > q, get the cnt;
//     // Can't caculate directly as we don't know the nodes with no edges, will TLE.
//     // Because combination of n is too big.
//     // But we have at most 10^5 emap[a,b] > 0. Not too much.
//     // So divide into two situation:
//     // (Note: Remember we only have nodes with edges in d and emap)
//     a. for d[a]+d[b]-emap[a,b] > q && emap[a,b] > 0:
//         caculate directly -> s1
//     b. for d[a]+d[b]-emap[a,b] > q && emap[a,b] = 0:
//         // Still can't caculate directly, find a work-around.
//         // What we want === d[a]+d[b]>q && emap[a,b]==0.
//         // We can caculate d[a]+d[b]>q (including emap[a,b] >0 || ==0) as s3,
//         // And d[a]+d[b] && emap[a,b]>0 as s2,
//         // Then s3 - s2;
//         1) find d[a]+d[b] > q: // use two pointers for sorted d
//             for j from begin and i from end to j, before they meet:
//                 find the min j to make d[j]+d[i]>q, the all points between i-j count
//                 s3 += i-j
//             ->s3
//         2) find d[a]+d[b] > q && emap[a,b]>0:
//             caculate directly -> s2 // just situation a but keeping duplicate e.
//     corresponding ans = s1 + s3 - s2

//        ans                     s3: d[a]+d[b]>q
//  ----------------------     ------------------------
//  |    s1        |     |     |                      |
//  |              |   --|---->|----------------------| 
//  |  emap[a,b]>0 |  =0 |     |       s2             |
//  |              |     |     | find d[a]+d[b] > q   |
//  |              |     |     |        && emap[a,b]>0|
//  -----------------------    ------------------------

// @lc code=start
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries)
    {
        vector<int> d(n + 1);
        unordered_map<int, int> cmap;
        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            if (a > b) swap(a, b);
            ++cmap[a * 100000 + b];
            ++d[a];
            ++d[b];
        }
        vector<int> ds(d.begin() + 1, d.end());
        sort(ds.begin(), ds.end());
        vector<int> ans;

        for (auto& q : queries) {
            int s1 = 0;
            int s2 = 0;
            int s3 = 0;
            for (auto [k, v] : cmap) {
                int a = k / 100000;
                int b = k % 100000;
                if (d[a] + d[b] - v > q) ++s1;
                if (d[a] + d[b] > q) ++s2;
            }
            for (int i = n - 1, j = 0; i > j; --i) {
                while (j < i && ds[j] + ds[i] <= q) ++j;
                if (j < i && ds[j] + ds[i] > q) s3 += i - j;
            }
            ans.push_back(s1 + s3 - s2);
        }
        return ans;
    }
};
// @lc code=end
