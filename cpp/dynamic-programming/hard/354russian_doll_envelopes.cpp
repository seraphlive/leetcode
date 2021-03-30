/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (36.54%)
 * Likes:    1703
 * Dislikes: 52
 * Total Accepted:    87.2K
 * Total Submissions: 238.4K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 * 
 * One envelope can fit into another if and only if both the width and height
 * of one envelope is greater than the width and height of the other envelope.
 * 
 * Return the maximum number of envelopes can you Russian doll (i.e., put one
 * inside the other).
 * 
 * Note: You cannot rotate an envelope.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= envelopes.length <= 5000
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^4
 * 
 * 
 */
// TODO: Learn LIS(longest increasing sequence)
// @lc code=start
// LIS (Leetcode Q.300), DP + greedy + binary search, O(nlogn) O(n)
using V = vector<int>;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int s = envelopes.size();
        sort(begin(envelopes), end(envelopes), [](const V& a, const V& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> col;
        for (auto& e : envelopes) {
            auto it = lower_bound(begin(col), end(col), e[1]);
            if (it == col.end()) col.push_back(e[1]);
            else if (*it > e[1]) *it = e[1];
        }
        return col.size();
    }
};
// @lc code=end

// Plain DP O(nlog(n)+n^2) O(n)
// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& e)
//     {
//         int s = e.size();
//         sort(begin(e), end(e));
//         // array to record max num an envenlope can hold.
//         int dp[s];
//         int res = 1;
//         dp[0] = 1;

//         for (int i = 1; i < s; ++i) {
//             dp[i] = 1;
//             for (int j = i - 1; j >= 0; --j) {
//                 if (e[i][0] > e[j][0] && e[i][1] > e[j][1])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };
