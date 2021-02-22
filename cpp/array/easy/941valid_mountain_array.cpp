/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (33.42%)
 * Likes:    797
 * Dislikes: 89
 * Total Accepted:    135.4K
 * Total Submissions: 405.8K
 * Testcase Example:  '[2,1]'
 *
 * Given an array of integers arr, return true if and only if it is a valid
 * mountain array.
 * 
 * Recall that arr is a mountain array if and only if:
 * 
 * 
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * 
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
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
// Two-pointers
class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        int i = 0, j = arr.size() - 1;
        while (i + 1 < arr.size() && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j] < arr[j - 1]) {
            --j;
        }
        return i > 0 && i == j && j < arr.size() - 1;
    }
};
// @lc code=end

