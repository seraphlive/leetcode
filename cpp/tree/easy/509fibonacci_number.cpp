/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (67.50%)
 * Likes:    1218
 * Dislikes: 224
 * Total Accepted:    345.1K
 * Total Submissions: 510.5K
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 * 
 * 
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * 
 * 
 * Given n, calculate F(n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 30
 * 
 * 
 */

// @lc code=start
// Binet's Formula, O(1), O(1)
// http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html
class Solution {
public:
    int fib(int n)
    {
        double phi = (sqrt(5) + 1) / 2;
        return round(pow(phi, n) / sqrt(5));
    }
};
// @lc code=end

// Iterative Bottom-up DP, O(n), O(1)
// class Solution {
// public:
//     int fib(int n)
//     {
//         if (n < 2) return n;
//         int fn_2 = 0;
//         int fn_1 = 1;
//         int fn = 0;
//         for (int i = 1; i < n; ++i) {
//             fn = fn_2 + fn_1;
//             fn_2 = fn_1;
//             fn_1 = fn;
//         }
//         return fn;
//     }
// };

// DP, O(n), O(n)
// class Solution {
// public:
//     int fib(int n)
//     {
//         if (n < 2) return n;
//         int dp[n + 1];
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
//         return dp[n];
//     }
// };

// Recursive, O(2^n);
// class Solution {
// public:
//     int fib(int n)
//     {
//         if (n == 0) return 0;
//         else if (n == 1) return 1;
//         else return fib(n - 1) + fib(n - 2);
//     }
// };
