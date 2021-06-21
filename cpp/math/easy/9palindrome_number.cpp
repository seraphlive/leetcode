/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (50.53%)
 * Likes:    3450
 * Dislikes: 1765
 * Total Accepted:    1.3M
 * Total Submissions: 2.6M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward. For
 * example, 121 is palindrome while 123 is not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: x = -101
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */

// @lc code=start
// Not using string. Cut and reverse last half and compare with first half.
class Solution {
public:
  bool isPalindrome(int x) {
    if (x == 0) return true;
    if (x < 0 || x % 10 == 0) return false;

    int last = 0;
    while (x > last) {
      last = last * 10 + x % 10;
      x /= 10;
    }
    return (x == last) || (x == last / 10);
  }
};
// @lc code=end

// Using string
// class Solution {
// public:
//   bool isPalindrome(int x) {
//     if (x < 0) return false;
//     if (x == 0) return true;

//     string s = to_string(x);
//     for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
//       if (s[i] != s[j]) return false;
//     }
//     return true;
//   }
// };
