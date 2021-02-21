/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (50.18%)
 * Likes:    1169
 * Dislikes: 398
 * Total Accepted:    119.1K
 * Total Submissions: 237.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */
// let d = 1 --> up-right, d = -1 --> down-left
// at r, c
//     // direction up-right    nr, nc = r-1, c+1
//     // direction down-left   nr, nc = r+1, c-1
//     d=1; nr, nc = r-d, c+d;
//     d=-1; nr, nc = r-d, c+d;

// if hit wall:
//     d = 1 --> go right ? go right : go down
//     d = -1 --> go down ? go down : go right

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return vector<int>();
        int M = matrix.size();
        int N = matrix[0].size();
        int r = 0;
        int c = 0;
        int d = 1;
        vector<int> res;

        while(res.size() != M * N) {
            res.push_back(matrix[r][c]);
            int nr = r - d;
            int nc = c + d;
            bool outBound = (nr < 0 || nr == M || nc < 0 || nc == N);
            if (outBound) {
                if (d == 1) {
                    if (nc == N) ++r;
                    else ++c;
                }
                else {
                    if (nr == M) ++c;
                    else ++r;
                }
                d = -d;
            }
            else {
                r = nr;
                c = nc;
            }
        }
        return res;
    }
};

// @lc code=end

// coordinate
// 0 (0, 0)
// 1 (0, 1) (1, 0)
// 2 (2, 0) (1, 1) (0, 2)
// 3 (1, 2) (2, 1)
// 4 (2, 2)
// for nth diag i+j== n - 1 -->max: m-1+n-1 = m+n-2

// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
//     {
//         vector<int> res;
//         if (matrix.empty()) return vector<int>();
//         const int M = matrix.size();
//         const int N = matrix[0].size();
        

//         for (int p = 0; p <= M + N - 2; ++p) {
//             for (int q = 0; q <= p; ++q) {
//                 int i = q;
//                 int j = p - i;

//                 if (p % 2 == 0) swap(i, j);
//                 if (i >= M || j >= N) continue;
//                 res.push_back(matrix[i][j]);
//             }
//         }
//         return res;
//     }
// };
