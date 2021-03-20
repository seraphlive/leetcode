/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (42.14%)
 * Likes:    1655
 * Dislikes: 78
 * Total Accepted:    100.4K
 * Total Submissions: 238.2K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * Given an integer array nums, return the length of the longest wiggle
 * sequence.
 * 
 * A wiggle sequence is a sequence where the differences between successive
 * numbers strictly alternate between positive and negative. The first
 * difference (if one exists) may be either positive or negative. A sequence
 * with fewer than two elements is trivially a wiggle sequence.
 * 
 * 
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
 * (6, -3, 5, -7, 3) are alternately positive and negative.
 * In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences,
 * the first because its first two differences are positive and the second
 * because its last difference is zero.
 * 
 * 
 * A subsequence is obtained by deleting some elements (eventually, also zero)
 * from the original sequence, leaving the remaining elements in their original
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 * 
 * Follow up: Could you solve this in O(n) time?
 * 
 */

// @lc code=start
// dp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int s = nums.size();
        // up[i]: length of longest wiggle sub (U) of nums[0~n], with positive end.
        vector<int> up(s, 0);
        // down[i]: length of longest wiggle sub (D) of nums[0~n], with negative end.
        vector<int> down(s, 0);
        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < s; ++i) {
            if (nums[i] > nums[i - 1]) {
                // the last item of type-D[i-1] is N
                // if nums[i] > N, nums[i] add to type-D[i] -> valid type-U
                // if nums[i] <= N, i.e. prev > N >= nums[i] > nums[i - 1], swap N with nums[i - 1]
                // new: prev > nums[i - 1] < nums[i] -> valid type-U
                up[i] = down[i - 1] + 1;
                // type-D no gains
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[s - 1], down[s - 1]);
    }
};
// @lc code=end
