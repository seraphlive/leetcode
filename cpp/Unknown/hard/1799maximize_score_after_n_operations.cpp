/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 *
 * https://leetcode.com/problems/maximize-score-after-n-operations/description/
 *
 * algorithms
 * Hard (38.39%)
 * Likes:    66
 * Dislikes: 3
 * Total Accepted:    1.7K
 * Total Submissions: 4.3K
 * Testcase Example:  '[1,2]'
 *
 * You are given nums, an array of positive integers of size 2 * n. You must
 * perform n operations on this array.
 * 
 * In the i^th operation (1-indexed), you will:
 * 
 * 
 * Choose two elements, x and y.
 * Receive a score of i * gcd(x, y).
 * Remove x and y from nums.
 * 
 * 
 * Return the maximum score you can receive after performing n operations.
 * 
 * The function gcd(x, y) is the greatest common divisor of x and y.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2]
 * Output: 1
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 2)) = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,6,8]
 * Output: 11
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6]
 * Output: 14
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 7
 * nums.length == 2 * n
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
// Bitmask DP
// https://www.bilibili.com/video/BV1Vh411X73n
class Solution {
public:
    int maxScore(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> f(1 << n);
        for (int i = 0; i < 1 << n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (!(i >> j & 1)) ++cnt;
            }
            cnt = cnt / 2 + 1;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (i >> k & 1)
                            f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + gcd(nums[j], nums[k]) * cnt);
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
private:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }
};
// @lc code=end

