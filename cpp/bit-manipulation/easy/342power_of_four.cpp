/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (42.07%)
 * Likes:    925
 * Dislikes: 258
 * Total Accepted:    236K
 * Total Submissions: 560.8K
 * Testcase Example:  '16'
 *
 * Given an integer n, return true if it is a power of four. Otherwise, return
 * false.
 *
 * An integer n is a power of four, if there exists an integer x such that n ==
 * 4^x.
 *
 *
 * Example 1:
 * Input: n = 16
 * Output: true
 * Example 2:
 * Input: n = 5
 * Output: false
 * Example 3:
 * Input: n = 1
 * Output: true
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
// 1. n > 0.
// 2. n only contains one bit of 1.
// 3. The 1 should be on odd bit position to exclude power of 2. use 0x55555555
// as a mask.
class Solution {
 public:
  bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
  }
};
// @lc code=end
