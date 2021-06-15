/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (38.73%)
 * Likes:    3502
 * Dislikes: 203
 * Total Accepted:    463.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
// Treat it as a sorted list.
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& mat, int t) {
    if (mat.empty() || mat[0].empty()) return false;
    int m = mat.size();
    int n = mat[0].size();

    int l = 0, r = m * n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (mat[mid / n][mid % n] > t) {
        r = mid - 1;
      } else if (mat[mid / n][mid % n] < t) {
        l = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

