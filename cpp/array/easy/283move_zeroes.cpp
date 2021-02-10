/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (58.50%)
 * Likes:    5002
 * Dislikes: 155
 * Total Accepted:    1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
// Read/write two pointers.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0, w = 0;
        for (; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                continue;
            } else {
                nums[w++] = nums[r];
            }
        }
        while (w < nums.size()) {
            nums[w++] = 0;
        }
    }
};
// @lc code=end

