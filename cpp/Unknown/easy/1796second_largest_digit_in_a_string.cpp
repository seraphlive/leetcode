/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 *
 * https://leetcode.com/problems/second-largest-digit-in-a-string/description/
 *
 * algorithms
 * Easy (46.12%)
 * Likes:    18
 * Dislikes: 19
 * Total Accepted:    4.9K
 * Total Submissions: 10.7K
 * Testcase Example:  '"dfa12321afd"'
 *
 * Given an alphanumeric string s, return the second largest numerical digit
 * that appears in s, or -1 if it does not exist.
 * 
 * An alphanumeric string is a string consisting of lowercase English letters
 * and digits.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dfa12321afd"
 * Output: 2
 * Explanation: The digits that appear in s are [1, 2, 3]. The second largest
 * digit is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abc1111"
 * Output: -1
 * Explanation: The digits that appear in s are [1]. There is no second largest
 * digit. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters and/or digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int secondHighest(string s)
    {
        int max = -1;
        int smax = -1;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                c -= '0';
                if (c > max) {
                    smax = max;
                    max = c;
                }
                else if (c != max && c > smax) smax = c;
                else continue;
            }
        }
        return smax;
    }
};
// @lc code=end

