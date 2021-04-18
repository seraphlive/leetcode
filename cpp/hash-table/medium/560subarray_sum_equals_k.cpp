/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.70%)
 * Likes:    7114
 * Dislikes: 245
 * Total Accepted:    467.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * continuous subarrays whose sum equals to k.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
// pref-sum w/ hashtable
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        // subarray[L..R] = pref[R] - pref[L - 1] = k
        int n = nums.size();
        int ans = 0;
        int pref = 0;
        unordered_map<int, int> cntPref;
        ++cntPref[pref];
        for (int R = 0; R < n; ++R) {
            // pref[L - 1] = pref[R] - k
            pref += nums[R];
            int need = pref - k;
            ans += cntPref[need];
            ++cntPref[pref];
        }
        return ans;
    }
};
// @lc code=end

