/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 *
 * https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
 *
 * algorithms
 * Medium (61.76%)
 * Likes:    83
 * Dislikes: 2
 * Total Accepted:    5.1K
 * Total Submissions: 8.3K
 * Testcase Example:  '12'
 *
 * Given an integer n, return true if it is possible to represent n as the sum
 * of distinct powers of three. Otherwise, return false.
 * 
 * An integer y is a power of three if there exists an integer x such that y ==
 * 3^x.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: true
 * Explanation: 12 = 3^1 + 3^2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 91
 * Output: true
 * Explanation: 91 = 3^0 + 3^2 + 3^4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 21
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^7
 * 
 * 
 */

// @lc code=start
// Math
class Solution {
public:
    bool checkPowersOfThree(int n)
    {
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
// @lc code=end

// Math
// class Solution {
// public:
//     bool checkPowersOfThree(int n)
//     {
//         while (n > 0 && n % 3 != 2) {
//             n = n % 3 == 1 ? n - 1 : n / 3;
//         }
//         return n == 0;
//     }
// };
