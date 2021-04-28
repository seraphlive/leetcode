/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (42.12%)
 * Likes:    145
 * Dislikes: 21
 * Total Accepted:    343.3K
 * Total Submissions: 809.9K
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 * 
 * 
 * Example 1:
 * Input: n = 27
 * Output: true
 * Example 2:
 * Input: n = 0
 * Output: false
 * Example 3:
 * Input: n = 9
 * Output: true
 * Example 4:
 * Input: n = 45
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
// O(1)
class Solution {
public:
    const int MAXP3INT = 1162261467;
    bool isPowerOfThree(int n)
    {
        if (n <= 0 || n > MAXP3INT) return false;
        return MAXP3INT % n == 0;
    }
};
// @lc code=end

// recursive
// class Solution {
// public:
//     bool isPowerOfThree(int n)
//     {
//         return n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)));
//     }
// };

// iterative
// class Solution {
// public:
//     bool isPowerOfThree(int n)
//     {
//         if (n > 1)
//             while(n % 3 == 0) n /= 3;
//         return n == 1;
//     }
// };
