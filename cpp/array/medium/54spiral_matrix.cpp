/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (35.74%)
 * Likes:    3477
 * Dislikes: 639
 * Total Accepted:    463K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
//  4x3 start from (0, -1)
//  right4 down2 left3 up1 right2 down0(quit)
//    0      1     2    3    
// let d = [[0,1],[1,0],[0,-1],[-1,0]]
// steps = [M, N-1]   [4, 2]
// while both steps still not 0:
//     id->even go l/r with M steps/odd go u/d with N steps
//     id always % 4 after inc

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<vector<int>> d {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> steps {m, n - 1};
        vector<int> res;

        int pd = 0;
        int r = 0, c = -1;
        while (steps[pd % 2]) {
            for (int i = 0; i < steps[pd % 2]; ++i) {
                r += d[pd][0];
                c += d[pd][1];
                res.push_back(matrix[r][c]);
            }
            --steps[pd % 2];
            pd = ++pd % 4;
        }
        return res;
    }
};
// @lc code=end

