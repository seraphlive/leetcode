/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    6813
 * Dislikes: 154
 * Total Accepted:    519.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you come up with the O(n^2) solution?
 * Could you improve it to O(n log(n)) time complexity?
 * 
 * 
 */

// @lc code=start
// DP + Greedy + Binary Search(O(logN)), O(NlogN) & O(N)
// For 2 seq with same length, smaller the last element is the better.
// dp[i]: the smallest ending number of a seq with length i+1.
// For each num, extend dp if it's greater than last element in dp;
// or replace the first element that is greater/equal to it in dp.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp;
        for (int n : nums) {
            auto it = lower_bound(begin(dp), end(dp), n);
            if (it == end(dp)) dp.push_back(n);
            else *it = n;
        }
        return dp.size();
    }
};
// @lc code=end

// Plain DP, O(N^2), O(N)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)
//     {
//         const int n = nums.size();
//         // dp[i]: max length of LIS ended with nums[i]
//         vector<int> dp(n, 1);
//         int res = 1;

//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };
