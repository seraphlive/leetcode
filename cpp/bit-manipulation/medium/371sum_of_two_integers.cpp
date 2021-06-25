/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (50.61%)
 * Likes:    1781
 * Dislikes: 2853
 * Total Accepted:    232.3K
 * Total Submissions: 459K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 *
 *
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * -1000 <= a, b <= 1000
 *
 *
 */

// @lc code=start
// Adding without carry: a^b. carry: (a & b) << 1.
class Solution {
 public:
  int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
  }
};
// @lc code=end
