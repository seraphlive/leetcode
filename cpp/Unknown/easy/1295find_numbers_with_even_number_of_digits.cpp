/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 *
 * https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/
 *
 * algorithms
 * Easy (79.34%)
 * Likes:    557
 * Dislikes: 70
 * Total Accepted:    221.7K
 * Total Submissions: 279.4K
 * Testcase Example:  '[12,345,2,6,7896]'
 *
 * Given an array nums of integers, return how many of them contain an even
 * number of digits.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [12,345,2,6,7896]
 * Output: 2
 * Explanation: 
 * 12 contains 2 digits (even number of digits). 
 * 345 contains 3 digits (odd number of digits). 
 * 2 contains 1 digit (odd number of digits). 
 * 6 contains 1 digit (odd number of digits). 
 * 7896 contains 4 digits (even number of digits). 
 * Therefore only 12 and 7896 contain an even number of digits.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [555,901,482,1771]
 * Output: 1 
 * Explanation: 
 * Only 1771 contains an even number of digits.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res += (int)log10(n) & 1;
        }
        return res;
    }
};
// @lc code=end

// Another solution using constraints:
// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int cnt = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int n = nums[i];
//             if ((n >= 10 && n <= 99) || (n >= 1000 && n <= 9999) || (n == 100000)) {
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };