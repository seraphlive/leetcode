/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (42.90%)
 * Likes:    402
 * Dislikes: 648
 * Total Accepted:    108.3K
 * Total Submissions: 252.1K
 * Testcase Example:  '[0,0,0,1]'
 *
 * In a given integer array nums, there is always exactly one largest element.
 * 
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array.
 * 
 * If it is, return the index of the largest element, otherwise return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the
 * array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return
 * 1.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return
 * -1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        int max = -1;
        int max_p = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
                max_p = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i == max_p) continue;
            if (max < nums[i] * 2) return -1;
        }
        return max_p;
    }
};
// @lc code=end
//
// One pass
// class Solution {
// public:
//     int dominantIndex(vector<int>& nums)
//     {
//         int max1 = 0;
//         int max2 = 0;
//         int max1_p = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] > max1) {
//                 max2 = max1;
//                 max1 = nums[i];
//                 max1_p = i;
//             }
//             else if (nums[i] > max2) {
//                 max2 = nums[i];
//             }
//         }
//         return max1 >= max2 * 2 ? max1_p : -1;
//     }
// };
