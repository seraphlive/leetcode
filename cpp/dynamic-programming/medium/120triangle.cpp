/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (46.13%)
 * Likes:    2799
 * Dislikes: 311
 * Total Accepted:    294.5K
 * Total Submissions: 638.3K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */
// [2]
// [3,4]
// [6,5,7]
// [4,1,8,3]
// @lc code=start
// DP inplace using input, O(n^2), O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t)
    {
        int n = t.size();
        // t[i][j] := minTotalOf(i, j)
        // t[i][j] += min(t[i-1][j], t[i-1][j-1])

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0 && j == 0) continue;
                else if (j == 0) t[i][j] += t[i - 1][j];
                else if (j == i) t[i][j] += t[i - 1][j - 1];
                else t[i][j] += min(t[i - 1][j], t[i - 1][j - 1]);
            }
        }
        return *min_element(t[n - 1].cbegin(), t[n - 1].cend());
    }
};
// @lc code=end

// DP rolling array, O(n^2), O(n)
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle)
//     {
//         int n = triangle.size();
//         // f[i][j] = minTotalOf(i, j)
//         // f[i][j] = min(f[i-1][j], f[i-1][j-1])+triangle[i-1][j-1]
//         vector<vector<int>> f(2, vector<int>(n + 1, INT_MAX));

//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= i; ++j) {
//                 f[1][j] = triangle[i - 1][j - 1];
//                 if (i == 1 && j == 1) continue;
//                 else if (j == 1) f[1][j] += f[0][j];
//                 else if (j == i) f[1][j] += f[0][j - 1];
//                 else f[1][j] += min(f[0][j], f[0][j - 1]);
//             }
//             swap(f[0], f[1]);
//         }
//         return *min_element(f[0].cbegin(), f[0].cend());
//     }
// };
