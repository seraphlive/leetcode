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

// @lc code=start
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries)
    {
        vector<int> d(n + 1);
        unordered_map<int, int> cnt;
        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            if (a > b) swap(a, b);
            ++cnt[a * 100000 + b];
            ++d[a];
            ++d[b];
        }
        vector<int> ds(d.begin() + 1, d.end());
        sort(ds.begin(), ds.end());
        vector<int> res;

        for (auto& q : queries) {
            int s1 = 0;
            int s2 = 0;
            int s3 = 0;
            for (auto [k, v] : cnt) {
                int a = k / 100000, b = k % 100000;
                if (d[a] + d[b] - v > q) ++s1;
                if (d[a] + d[b] > q) ++s2;
            }
            for (int i = n - 1, j = 0; i > j; --i) {
                while (j < i && ds[j] + ds[i] <= q) ++j;
                if (j < i && ds[j] + ds[i] > q) s3 += i - j;
            }
            res.push_back(s1 + s3 - s2);
        }
        return res;
    }
};
// @lc code=end

