/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 *
 * https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
 *
 * algorithms
 * Hard (37.16%)
 * Likes:    105
 * Dislikes: 9
 * Total Accepted:    2.8K
 * Total Submissions: 6.9K
 * Testcase Example:  '[1,4,3,7,4,5]\n3'
 *
 * You are given an array of integers nums (0-indexed) and an integer k.
 * 
 * The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ...,
 * nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
 * 
 * Return the maximum possible score of a good subarray.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,3,7,4,5], k = 3
 * Output: 15
 * Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) *
 * (5-1+1) = 3 * 5 = 15. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,5,4,5,4,1,1,1], k = 0
 * Output: 20
 * Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) *
 * (4-0+1) = 4 * 5 = 20.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 2 * 10^4
 * 0 <= k < nums.length
 * 
 * 
 */

// @lc code=start
// Two-pointers, greedy. O(n) O(1)
// Start with i = j = k, score = nums[k]
// Then increase the window step by step:
//     if nums[i - 1] < nums[j + 1]: ++j;
//     if nums[i - 1] >= nums[j + 1]: --i;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k)
    {
        int res = nums[k];
        int minv = nums[k];
        int i = k;
        int j = k;
        while (i > 0 || j < nums.size() - 1) {
            if ((i > 0 ? nums[i - 1] : 0) < (j < nums.size() - 1 ? nums[j + 1] : 0))
                minv = min(minv, nums[++j]);
            else
                minv = min(minv, nums[--i]);
            res = max(res, minv * (j - i + 1));
        }
        return res;
    }
};
// @lc code=end

