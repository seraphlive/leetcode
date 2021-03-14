/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (39.59%)
 * Likes:    3481
 * Dislikes: 138
 * Total Accepted:    340.8K
 * Total Submissions: 860.9K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
 * numsr-1, numsr] of which the sum is greater than or equal to target. If
 * there is no such subarray, return 0 instead.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
// Two-pointers. O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int l = 0, r = 0, sum = 0, len = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end

// binary search and some math. O(nlogn) O(n)
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums)
//     {
//         int len = INT_MAX;
//         vector<int> sums(nums.size() + 1, 0);
//         for (int i = 1; i <= nums.size(); ++i) {
//             sums[i] = sums[i - 1] + nums[i - 1];
//         }
//         for (int i = nums.size(); i >= 0 && sums[i] >= s; --i) {
//             int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
//             len = min(len, i - j + 1);
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };
