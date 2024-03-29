/*
 * @lc app=leetcode id=941 lang=java
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (32.24%)
 * Likes:    564
 * Dislikes: 81
 * Total Accepted:    96.2K
 * Total Submissions: 298.3K
 * Testcase Example:  '[2,1]'
 *
 * Given an array of integers arr, return true if and only if it is a valid
 * mountain array.
 * 
 * Recall that arr is a mountain array if and only if:
 * 
 * 
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * 
 * arr[0] < arr[1] < ... < arr[i - 1] < A[i] 
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * Input: arr = [2,1]
 * Output: false
 * Example 2:
 * Input: arr = [3,5,5]
 * Output: false
 * Example 3:
 * Input: arr = [0,3,2,1]
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean validMountainArray(int[] arr) {
        int i = 0, j = arr.length - 1;
        while (i < j) {
            if (arr[i] < arr[i + 1]) {
                i++;
            } else if (arr[j] < arr[j - 1]) {
                j--;
            } else {
                break;
            }
        }
        return i != 0 && j != arr.length - 1 && i == j;
    }
}
// @lc code=end

