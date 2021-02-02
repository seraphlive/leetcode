/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 *
 * https://leetcode.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (52.04%)
 * Likes:    783
 * Dislikes: 273
 * Total Accepted:    123.5K
 * Total Submissions: 237.5K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * Given a fixed length array arr of integers, duplicate each occurrence of
 * zero, shifting the remaining elements to the right.
 * 
 * Note that elements beyond the length of the original array are not written.
 * 
 * Do the above modifications to the input array in place, do not return
 * anything from your function.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, the input array is modified to:
 * [1,0,0,2,3,0,0,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3]
 * Output: null
 * Explanation: After calling your function, the input array is modified to:
 * [1,2,3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
 * 
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n) {
                A[j] = A[i];
            }
            if (A[i] == 0 && --j < n) {
                A[j] = 0;
            }
        }
    }
};
// @lc code=end

