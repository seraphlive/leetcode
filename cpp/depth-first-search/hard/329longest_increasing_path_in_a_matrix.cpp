/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (45.31%)
 * Likes:    2915
 * Dislikes: 52
 * Total Accepted:    203.5K
 * Total Submissions: 447.8K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 * 
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
// DFS + memorization (Top-down)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return 0;
        m_ = matrix.size();
        n_ = matrix[0].size();
        dp_ = vector<vector<int>>(m_, vector<int>(n_, -1));
        int ans = 0;
        for (int y = 0; y < m_; ++y) {
            for (int x = 0; x < n_; ++x) {
                ans = max(ans, dfs(matrix, x, y));
            }
        }
        return ans;
    }
private:
    int dfs(const vector<vector<int>>& mat, int x, int y)
    {
        if (dp_[y][x] != -1) return dp_[y][x];
        static int dirs[] = {0, -1, 0, 1, 0};
        dp_[y][x] = 1;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dirs[i];
            int dy = y + dirs[i + 1];
            if (dx < 0 || dy < 0 || dx >= n_ || dy >= m_ || mat[dy][dx] <= mat[y][x])
                continue;
            dp_[y][x] = max(dp_[y][x], 1 + dfs(mat, dx, dy));
        }
        return dp_[y][x];
    }

    int m_, n_;
    vector<vector<int>> dp_;
};
// @lc code=end

// DP (Bottom-up)
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix)
//     {
//         if (matrix.empty()) return 0;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 1));
//         int ans = 0;

//         vector<pair<int, pair<int, int>>> cells;
//         for (int y = 0; y < m; ++y) {
//             for (int x = 0; x < n; ++x) {
//                 cells.push_back({matrix[y][x], {x, y}});
//             }
//         }
//         sort(cells.rbegin(), cells.rend());

//         vector<int> dirs = {0, 1, 0, -1, 0};
//         for (const auto& cell : cells) {
//             int x = cell.second.first;
//             int y = cell.second.second;
//             for (int i = 0; i < 4; ++i) {
//                 int dx = x + dirs[i];
//                 int dy = y + dirs[i + 1];
//                 if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
//                 if (matrix[dy][dx] <= matrix[y][x]) continue;
//                 dp[y][x] = max(dp[y][x], 1 + dp[dy][dx]);
//             }
//             ans = max(ans, dp[y][x]);
//         }
//         return ans;
//     }
// };
