/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (65.99%)
 * Likes:    1440
 * Dislikes: 95
 * Total Accepted:    130.8K
 * Total Submissions: 198.3K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise,
 * return false.
 * 
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: true
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2],[2,2]]
 * Output: false
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 20
 * 0 <= matrix[i][j] <= 99
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the matrix is stored on disk, and the memory is limited such that
 * you can only load at most one row of the matrix into the memory at once?
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 * 
 * 
 */

// @lc code=start
// Easy brute force - O(n^2), check if there is a diagonal that has different
// element, then return false;
class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& m) {
    for (int i = 0; i < m.size() - 1; ++i) {
      for (int j = 0; j < m[i].size() - 1; ++j) {
        if (m[i][j] != m[i + 1][j + 1]) return false;
      }
    }
    return true;
  }
};
// @lc code=end

// Follow up 1: load half of current row and half of next row to compare. (Need
// overlapping)
// Follow up 2: seperate into sub matrix that can fit in the window, then do 1.
