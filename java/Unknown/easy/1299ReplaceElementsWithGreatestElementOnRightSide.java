/*
 * @lc app=leetcode id=1299 lang=java
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 *
 * https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/
 *
 * algorithms
 * Easy (74.57%)
 * Likes:    549
 * Dislikes: 132
 * Total Accepted:    91.7K
 * Total Submissions: 123.2K
 * Testcase Example:  '[17,18,5,4,6,1]'
 *
 * Given an array arr, replace every element in that array with the greatest
 * element among the elements to its right, and replace the last element with
 * -1.
 * 
 * After doing so, return the array.
 * 
 * 
 * Example 1:
 * Input: arr = [17,18,5,4,6,1]
 * Output: [18,6,6,6,1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 * 
 */

// @lc code=start
class Solution {
    public int[] replaceElements(int[] arr) {
        int mx = -1, n = arr.length, tmp;
        for (int i = n - 1; i >= 0; i--) {
            tmp = arr[i];
            arr[i] = mx;
            mx = Math.max(mx, tmp);
        }
        return arr;
    }
}
// @lc code=end

