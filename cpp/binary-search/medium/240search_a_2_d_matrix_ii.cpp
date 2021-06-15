/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (45.81%)
 * Likes:    4908
 * Dislikes: 93
 * Total Accepted:    461.5K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix. The matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
// binary-search like method, O(m + n) (iterate each row and each col at most)
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& mat, int t) {
    if (mat.empty() || mat[0].empty()) return false;
    int m = mat.size();
    int n = mat[0].size();

    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
      if (mat[row][col] == t) {
        return true;
      } else if (mat[row][col] < t) {
        // All elements in current row on the left of current element < current
        // If current < t, this row can be skipped.
        ++row;
      } else {
        // All elements in current col below current element < current
        // If current > t, this col can be skipped.
        --col;
      }
    }
    return false;
  }
};
// @lc code=end

// brute binary search O(mlogn)
// class Solution {
// public:
//   bool searchMatrix(vector<vector<int>>& mat, int t) {
//     if (mat.empty() || mat[0].empty()) return false;
//     int m = mat.size();
//     int n = mat[0].size();

//     for (int i = 0; i < m; ++i) {
//       int l = 0, r = n - 1;
//       while (l <= r) {
//         int mid = l + (r - l) / 2;
//         if (mat[i][mid] == t) {
//           return true;
//         } else if (mat[i][mid] > t) {
//           r = mid - 1;
//         } else {
//           l = mid + 1;
//         }
//       }
//     }
//     return false;
//   }
// };