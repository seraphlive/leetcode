/*
 * @lc app=leetcode id=1840 lang=cpp
 *
 * [1840] Maximum Building Height
 *
 * https://leetcode.com/problems/maximum-building-height/description/
 *
 * algorithms
 * Hard (27.34%)
 * Likes:    63
 * Dislikes: 2
 * Total Accepted:    1.3K
 * Total Submissions: 4.4K
 * Testcase Example:  '5\n[[2,1],[4,1]]'
 *
 * You want to build n new buildings in a city. The new buildings will be built
 * in a line and are labeled from 1 to n.
 * 
 * However, there are city restrictions on the heights of the new
 * buildings:
 * 
 * 
 * The height of each building must be a non-negative integer.
 * The height of the first building must be 0.
 * The height difference between any two adjacent buildings cannot exceed 1.
 * 
 * 
 * Additionally, there are city restrictions on the maximum height of specific
 * buildings. These restrictions are given as a 2D integer array restrictions
 * where restrictions[i] = [idi, maxHeighti] indicates that building idi must
 * have a height less than or equal to maxHeighti.
 * 
 * It is guaranteed that each building will appear at most once in
 * restrictions, and building 1 will not be in restrictions.
 * 
 * Return the maximum possible height of the tallest building.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, restrictions = [[2,1],[4,1]]
 * Output: 2
 * Explanation: The green area in the image indicates the maximum allowed
 * height for each building.
 * We can build the buildings with heights [0,1,2,1,2], and the tallest
 * building has a height of 2.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, restrictions = []
 * Output: 5
 * Explanation: The green area in the image indicates the maximum allowed
 * height for each building.
 * We can build the buildings with heights [0,1,2,3,4,5], and the tallest
 * building has a height of 5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
 * Output: 5
 * Explanation: The green area in the image indicates the maximum allowed
 * height for each building.
 * We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the
 * tallest building has a height of 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^9
 * 0 <= restrictions.length <= min(n - 1, 10^5)
 * 2 <= idi <= n
 * idi is unique.
 * 0 <= maxHeighti <= 10^9
 * 
 * 
 */

// @lc code=start
// Linear programming
using LL = long long;
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& h)
    {
        h.push_back({1, 0});
        sort(h.begin(), h.end());
        if (h.back()[0] != n) h.push_back({n, n - 1});
        int m = h.size();
        vector<LL> f(m + 1, INT_MAX), g(m + 1, INT_MAX);
        f[0] = -1;
        for (int i = 1; i < m; ++i) {
            int x = h[i][0], y = h[i][1];
            f[i] = min(f[i - 1], static_cast<LL>(y) - x);
        }
        for (int i = m - 1; i >= 0; --i) {
            int x = h[i][0], y = h[i][1];
            g[i] = min(g[i + 1], static_cast<LL>(y) + x);
        }
        LL res = 0;
        for (int i = 0; i < m; ++i) {
            int x = h[i][0];
            if (i > 1) {
                LL Y = (f[i - 1] + g[i]) / 2;
                LL X = Y - f[i - 1];
                if (X >= h[i - 1][0] && X <= h[i][0]) res = max(res, Y);
            }
            res = max(res, min(x + f[i], g[i] - x));
        }
        return res;
    }
};
// @lc code=end

