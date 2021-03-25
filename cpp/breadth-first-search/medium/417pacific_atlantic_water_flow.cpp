/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (42.71%)
 * Likes:    1870
 * Dislikes: 461
 * Total Accepted:    106.5K
 * Total Submissions: 247.4K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */
// TODO: BFS and DP method
// @lc code=start 
// Reverse the process. Find all reachable nodes of P and A.
// ans = R(P) ∩ R(A)
// BFS ver.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {

    }
};
// @lc code=end

// Reverse the process. Find all reachable nodes of P and A.
// ans = R(P) ∩ R(A)
// DFS ver.
// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
//     {
//         if (matrix.empty()) return {};
//         const int n = matrix.size();
//         const int m = matrix[0].size();

//         vector<vector<int>> p(n, vector<int>(m));
//         vector<vector<int>> a(n, vector<int>(m));

//         for (int x = 0; x < m; ++x) {
//             dfs(matrix, x, 0, 0, p); // top
//             dfs(matrix, x, n - 1, 0, a); // bottom
//         }

//         for (int y = 0; y < n; ++y) {
//             dfs(matrix, 0, y, 0, p); // left
//             dfs(matrix, m - 1, y, 0, a); // right
//         }

//         vector<vector<int>> ans;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (p[i][j] && a[i][j]) ans.emplace_back(vector<int>{i, j});
//             }
//         }
//         return ans;
//     }
// private:
//     void dfs(vector<vector<int>>& m, int x, int y, int h, vector<vector<int>>& v)
//     {
//         if (x < 0 || y < 0 || x == m[0].size() || y == m.size()) return;
//         if (v[y][x] || m[y][x] < h) return;
//         v[y][x] = 1;
//         dfs(m, x + 1, y, m[y][x], v);
//         dfs(m, x - 1, y, m[y][x], v);
//         dfs(m, x, y + 1, m[y][x], v);
//         dfs(m, x, y - 1, m[y][x], v);
//     }
// };

// brute force DFS, O(4^(mn)), TLE
// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
//     {
//         vector<vector<int>> ans;
//         for (int i = 0; i < matrix.size(); ++i) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 if (dfs(matrix, j, i, matrix[i][j]) == 3)
//                     ans.emplace_back(vector<int>{i, j});
//             }
//         }
//         return ans;
//     }
// private:
//     int dfs(vector<vector<int>>& matrix, int x, int y, int h)
//     {
//         if (x < 0 || y < 0) return 1;
//         if (x == matrix[0].size() || y == matrix.size()) return 2;
//         if (matrix[y][x] > h) return 0;
//         h = matrix[y][x];
//         matrix[y][x] = INT_MAX;
//         int valid = dfs(matrix, x + 1, y, h) |
//                     dfs(matrix, x - 1, y, h) |
//                     dfs(matrix, x, y + 1, h) |
//                     dfs(matrix, x, y - 1, h);
//         matrix[y][x] = h;
//         return valid;
//     }
// };
