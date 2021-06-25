/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 *
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (60.20%)
 * Likes:    684
 * Dislikes: 95
 * Total Accepted:    78K
 * Total Submissions: 129.5K
 * Testcase Example:  '5'
 *
 * Given a positive integer, check whether it has alternating bits: namely, if
 * two adjacent bits will always have different values.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: true
 * Explanation: The binary representation of 5 is: 101
 *
 *
 * Example 2:
 *
 *
 * Input: n = 7
 * Output: false
 * Explanation: The binary representation of 7 is: 111.
 *
 * Example 3:
 *
 *
 * Input: n = 11
 * Output: false
 * Explanation: The binary representation of 11 is: 1011.
 *
 * Example 4:
 *
 *
 * Input: n = 10
 * Output: true
 * Explanation: The binary representation of 10 is: 1010.
 *
 * Example 5:
 *
 *
 * Input: n = 3
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int cur = n & 1;
    n >>= 1;
    while (n) {
      if (!(cur ^ (n & 1))) return false;
      cur = n & 1;
      n >>= 1;
    }
    return true;
  }
};
// @lc code=end

// If a number is 010101..., right shift 1 bit and XOR, then result must be
// 000011111... AND result with result+1 to get 0 if result is 000001111111....
// class Solution {
//  public:
//   bool hasAlternatingBits(int n) {
//     long res = n ^ (n >> 1);
//     return (res & (res + 1)) == 0;
//   }
// };
