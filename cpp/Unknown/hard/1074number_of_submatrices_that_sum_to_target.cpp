/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (62.06%)
 * Likes:    1034
 * Dislikes: 32
 * Total Accepted:    34.6K
 * Total Submissions: 53.6K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix and a target, return the number of non-empty submatrices that
 * sum to target.
 * 
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 * 
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[904]], target = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        vector<int> row(matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i) {
            fill(row.begin(), row.end(), 0);
            for (int j = i; j < matrix.size(); ++j) {
                for (int k = 0; k < matrix[0].size(); ++k)
                    row[k] += matrix[j][k];
                get_result(row, target);
            }
        }
        return res;
    }
private:
    int res = 0;
    unordered_map<int, int> cntPref;

    void get_result(vector<int>& nums, int target)
    {
        int sum = 0;
        int pref = 0;
        cntPref.clear();
        ++cntPref[pref];
        for (int& n : nums) {
            pref += n;
            int need = pref - target;
            res += cntPref[need];
            ++cntPref[pref];
        }
    }
};
// @lc code=end

