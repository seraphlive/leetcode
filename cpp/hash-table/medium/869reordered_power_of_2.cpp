/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (54.39%)
 * Likes:    273
 * Dislikes: 104
 * Total Accepted:    18.6K
 * Total Submissions: 33.6K
 * Testcase Example:  '1'
 *
 * Starting with a positive integer N, we reorder the digits in any order
 * (including the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this in a way such that the resulting
 * number is a power of 2.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 24
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 46
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
// Use hash table if N > 10^9
class Solution {
public:
    bool reorderedPowerOf2(int N)
    {
        long c = counter(N);
        for (int i = 0; i < 31; ++i) {
            if (counter(1 << i) == c) return true;
        }
        return false;
    }
private:
    long counter(int N)
    {
        long res = 0;
        for (; N > 0; N /= 10) res += pow(10, N % 10);
        return res;
    }
};
// @lc code=end

