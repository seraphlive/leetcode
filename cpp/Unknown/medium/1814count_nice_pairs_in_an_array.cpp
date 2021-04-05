/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 *
 * https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (34.08%)
 * Likes:    118
 * Dislikes: 11
 * Total Accepted:    3.8K
 * Total Submissions: 10.7K
 * Testcase Example:  '[42,11,1,97]'
 *
 * You are given an array nums that consists of non-negative integers. Let us
 * define rev(x) as the reverse of the non-negative integer x. For example,
 * rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it
 * satisfies all of the following conditions:
 * 
 * 
 * 0 <= i < j < nums.length
 * nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
 * 
 * 
 * Return the number of nice pairs of indices. Since that number can be too
 * large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [42,11,1,97]
 * Output: 2
 * Explanation: The two pairs are:
 * ⁠- (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 * ⁠- (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [13,10,35,24,76]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            int x = n;
            string s = to_string(x);
            reverse(s.begin(), s.end());
            int y = stoi(s);
            ++cnt[x - y];
        }
        const int MOD = 1e9 + 7;
        int res = 0;

        for (auto [k, v] : cnt) {
            res = (res + static_cast<long long>(v) * (v - 1) / 2) % MOD;
        }
        return res;
    }
};
// @lc code=end

