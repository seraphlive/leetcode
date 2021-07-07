/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (32.92%)
 * Likes:    738
 * Dislikes: 395
 * Total Accepted:    87.2K
 * Total Submissions: 265K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, decide whether there're two integers a and b
 * such that a^2 + b^2 = c.
 *
 *
 * Example 1:
 *
 *
 * Input: c = 5
 * Output: true
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 *
 * Example 2:
 *
 *
 * Input: c = 3
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: c = 4
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: c = 2
 * Output: true
 *
 *
 * Example 5:
 *
 *
 * Input: c = 1
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= c <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool judgeSquareSum(int c) {
    if (c < 0) return false;
    int l = 0, r = (int)sqrt(c);
    while (l <= r) {
      long sum = (long)l * l + r * r;
      if (sum == c) {
        return true;
      } else if (sum > c) {
        --r;
      } else {
        ++l;
      }
    }
    return false;
  }
};
// @lc code=end
